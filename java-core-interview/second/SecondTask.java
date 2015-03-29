class SyncThread implements Runnable {
    private Object firstMonitor;
    private Object secondMonitor;
 
    public SyncThread(Object m1, Object m2){
        this.firstMonitor = m1;
        this.secondMonitor = m2;
    }
    @Override
    public void run() {
        synchronized (firstMonitor) {
            doTheFoo();
            synchronized (secondMonitor) {
                doTheBar();
            }
        }
    }
    private void doTheFoo() {
        try {
            Thread.sleep(10000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
    private void doTheBar() {
        try {
            Thread.sleep(10000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("You have completed the second task!");
    }
}


public class SecondTask {
  public static void main(String[] args) throws InterruptedException {
    Object firstMonitor = new Object();
    Object secondMonitor = new Object();
    Object thirdMonitor = new Object();
 
    Thread t1 = new Thread(new SyncThread(firstMonitor, secondMonitor), "t1");
    Thread t2 = new Thread(new SyncThread(secondMonitor, thirdMonitor), "t2");
    Thread t3 = new Thread(new SyncThread(thirdMonitor, firstMonitor), "t3");
     
    t1.start();
    Thread.sleep(5000);
    t2.start();
    Thread.sleep(5000);
    t3.start();
  }
}

