// PFM module
class TransportMessageHandler implements Runnable{

public void run() {
}

}

class TransactionData {
    class BufferWrapper {
        bytebuffer msg;
        TimerHandler timer;
    };
    public static HashMap<int, BufferWrapper> MessageRef;

}

class FEPHandler implements Runnable {
    static class Rule {
        int appId;
        int commandCode;
        string originRealm; // regex form
        string destRealm; // regex form
        string originIP; // regex form
        string destIP; // regex form
    };

    private static HashMap<int, Rule>  ruleMap; // <ruleid, rule structure>

    static AddRule (int ID, Rule rule);
    static deleteRule (int ID, Rule rule);

    public static ProcessFrontEndExclusion(DiaPacket dp) {
        bool matched = false;
        for (int ruleID : ruleMap.keySet()) {
            // Mactch rule magic
        }
        if (matched) return true;
        else return false;
    }

    public void run () {
        try {
            WatchService watcher = FileSystems.getDefault().newWatchService();
            Path dir = Paths.get("/Users/piyushvijay/Downloads");
            dir.register(watcher, ENTRY_CREATE, ENTRY_DELETE, ENTRY_MODIFY);

            System.out.println("Watch Service registered for dir: " + dir.getFileName());

            while (true) {
                WatchKey key;
                try {
                    key = watcher.take();
                } catch (InterruptedException ex) {
                    return;
                }

                for (WatchEvent<?> event : key.pollEvents()) {
                    WatchEvent.Kind<?> kind = event.kind();

                    @SuppressWarnings("unchecked")
                    WatchEvent<Path> ev = (WatchEvent<Path>) event;
                    Path fileName = ev.context();

                    System.out.println(kind.name() + ": " + fileName);

                    if (kind == ENTRY_MODIFY &&
                            fileName.toString().equals("FEP-Config.xml")) {
                        System.out.println("My source file has changed!!!");
                        // Synchronize config,re-read and update the local cache of
                        // FEP config
                            }
                }

                boolean valid = key.reset();
                if (!valid) {
                    break;
                }
            }

        } catch (IOException ex) {
            System.err.println(ex);
        }

    }
}
