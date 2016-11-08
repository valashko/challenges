#pragma once

#include <memory>
#include <stdexcept>
#include <typeinfo>


namespace Prism
{
// inspired by boost:any
class Pixel final
{
public:
  template< typename PixelType >
  Pixel(const PixelType & value):
      holder_(new PixelTypeHolder<PixelType>(value))
  { }

  template< typename OtherType >
  bool castIsValid() const
  {
    return typeid(OtherType) == holder_->valueType();
  }

  template< typename OtherType >
  OtherType cast() const
  {
    if(castIsValid< OtherType >()) {
      // I would like to do this, however it is not possible:
      // return static_cast<std::unique_ptr< PixelTypeHolder<OtherType> > >(holder_)->t_;
      return static_cast< PixelTypeHolder<OtherType> * >(holder_.get())->value_;
    } else {
      // TODO improve with abi::__cxa_demangle to get readable type names
      throw BadCast(typeid(OtherType).name(), holder_->valueType().name());
    }
  }

  class BadCast final : public std::runtime_error
  {
  public:
    BadCast(const std::string & actualTypeName, const std::string & requestedTypeName):
        std::runtime_error("Cannot cast " + actualTypeName + " to " + requestedTypeName)
    { }
  };

private:
  class PixelTypeHolderBase
  {
  public: // since this is a nested private class, nobody will be able to access these anyways
    virtual const std::type_info & valueType() const = 0;
    virtual ~PixelTypeHolderBase() { }
  };
  
  template< typename PixelType >
  class PixelTypeHolder final : public PixelTypeHolderBase
  {
  public: // since this is a nested private class, nobody will be able to access these anyways
    PixelTypeHolder(const PixelType& value):
        value_(value)
    { }
    
    virtual const std::type_info & valueType() const override
    {
      return typeid(PixelType);
    }
    
    PixelType value_;
  };


  std::unique_ptr< PixelTypeHolderBase > holder_;
};
}

