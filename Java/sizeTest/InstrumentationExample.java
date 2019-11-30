import java.util.ArrayList;
import java.util.List;
public class InstrumentationExample {

    public static void printObjectSize(Object object) {
        System.out.println("Object type: " + object.getClass() +
          ", size: " + InstrumentationAgent.getObjectSize(object) + " bytes");
    }

    public static void main(String[] arguments) {
        String emptyString = "";
        String string = "Estimating Object Size Using Instrumentation";
        String[] stringArray = { emptyString, string, "com.baeldung" };
        String[] anotherStringArray = new String[100];
        List<String> stringList = new ArrayList<>();
        StringBuilder stringBuilder = new StringBuilder(100);
        int maxIntPrimitive = Integer.MAX_VALUE;
        int minIntPrimitive = Integer.MIN_VALUE;
        Integer maxInteger = Integer.MAX_VALUE;
        Integer minInteger = Integer.MIN_VALUE;
        long zeroLong = 0L;
        double zeroDouble = 0.0;
        boolean falseBoolean = false;
        Object object = new Object();

        class EmptyClass {
        }
        EmptyClass emptyClass = new EmptyClass();

        class StringClass {
            public String s;
        }
        StringClass stringClass = new StringClass();

        printObjectSize(emptyString);
        printObjectSize(string);
        printObjectSize(stringArray);
        printObjectSize(anotherStringArray);
        printObjectSize(stringList);
        printObjectSize(stringBuilder);
        printObjectSize(maxIntPrimitive);
        printObjectSize(minIntPrimitive);
        printObjectSize(maxInteger);
        printObjectSize(minInteger);
        printObjectSize(zeroLong);
        printObjectSize(zeroDouble);
        printObjectSize(falseBoolean);
        printObjectSize(Day.TUESDAY);
        printObjectSize(LogPktEnum.PKT_RCVD);
        printObjectSize(object);
        printObjectSize(emptyClass);
        printObjectSize(stringClass);
    }

    public enum Day {
        MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY
    }
     public enum LogPktEnum {
	PKT_RCVD,
	PKT_DECODE_SUCCESS,
	PKT_DECODE_FAIL,
	PKT_WITHOUT_SESSION,
	PKT_PICKED_PROCESSING,
	PKT_BYPASS_ENABLED,
	PKT_PROCESS_OUTCOME,
	PKT_CONGESTED,
	PKT_FEP_NOT_APPLIED,
	PKT_FEP_APPLIED,
	PKT_LCP_PROCESSING,
	PKT_LCP_MCC_REALM,
	PKT_LCP_MNC_REALM,
	PKT_LCP_MCC_VPLM,
	PKT_LCP_MNC_VPLM,
	PKT_LCP_ADDR_DECODE_FAIL,
	PKT_SEND_KAFKA,
	PKT_KAFKA_EXCEPTION,
	PKT_KAFKA_NOT_AVAILABLE,
	PKT_KAFKA_SEND_SUCCESS,
	PKT_KAFKA_SEND_STATE_MISMATCH,
	PKT_HAUD_RESP_RCVD,
	PKT_HAUD_RESP_FLTR_BYPASS,
	PKT_HAUD_RESP_BLK_SILENT,
	PKT_HAUD_RESP_BLK_WITH_ERROR,
	PKT_HAUD_RESP_BLK_WITH_ERROR_RESP,
	PKT_HAUD_RESP_MIRROR,
	PKT_HAUD_RESP_DEFAULT,
	PKT_HAUD_RESP_TRANS_STATE_MISMATCH,
	PKT_DEFAULT_ACTION,
	PKT_DEFAULT_DROP,
	PKT_DEFAULT_RESP_ERROR,
	PKT_DEFAULT_FORWARD,
	PKT_DEFAULT_UNKNOWN,
	PKT_DEFAULT_RESP_ERROR_FAIL,

	//Failover logs
	PKT_FAILOVER_MSG,
	PKT_FAILOVER_MSG_ERROR,
	PKT_FAILOVER_MSG_TIMEOUT,
	PKT_FAILOVER_MSG_REQ_FRM_KAFKA,
	PKT_FAILOVER_TUNNEL_NOT_UP,
	PKT_FAILOVER_TUNNEL_NO_CER,
	PKT_FAILOVER_TUNNEL_NOT_FOUND,
	PKT_FAILOVER_TUNNEL_PEER_NOT_FOUND,

	PKT_PCAP_RULE_MATCHED,
	MAX_LOG_INDEX;
    }

  public static String[] pktLogs = new String[LogPktEnum.MAX_LOG_INDEX.ordinal()];

    public static void populatePktLogStatement() {
	pktLogs[LogPktEnum.PKT_RCVD.ordinal()] = "Diameter packet entered the system : {}\n";
	pktLogs[LogPktEnum.PKT_DECODE_SUCCESS.ordinal()] = "Diameter packet decoded successfuly";
	pktLogs[LogPktEnum.PKT_DECODE_FAIL.ordinal()] = "Diameter packet decoded failed";
	pktLogs[LogPktEnum.PKT_PICKED_PROCESSING.ordinal()] = "Diameter packet picked for processing.";
	pktLogs[LogPktEnum.PKT_WITHOUT_SESSION.ordinal()] = "Received diameter packet without session-id....Droping.";
	pktLogs[LogPktEnum.PKT_BYPASS_ENABLED.ordinal()] = "Bypass mode enabled sending diameter packet without further processing";
	pktLogs[LogPktEnum.PKT_CONGESTED.ordinal()] = "Congestion dected, applying configured default action : {}....!";
	pktLogs[LogPktEnum.PKT_FEP_NOT_APPLIED.ordinal()] = "Multiple occurence of Origin/Destination Realm AVP, FEP rules not applied....!";
	pktLogs[LogPktEnum.PKT_FEP_APPLIED.ordinal()] = "FEP rule matched {}, bypassing diameter packet...!";
	pktLogs[LogPktEnum.PKT_LCP_PROCESSING.ordinal()] = "LCP action set to BLACKLIST";
	pktLogs[LogPktEnum.PKT_LCP_MCC_REALM.ordinal()] = "Extracted MCC in realm {}";
	pktLogs[LogPktEnum.PKT_LCP_MNC_REALM.ordinal()] = "Extracted MNC in realm {}";
	pktLogs[LogPktEnum.PKT_LCP_MCC_VPLM.ordinal()] = "Extracted MCC in VPLMN-ID {}";
	pktLogs[LogPktEnum.PKT_LCP_MNC_VPLM.ordinal()] = "Extracted MNC in VPLMN-ID {}";
	pktLogs[LogPktEnum.PKT_LCP_ADDR_DECODE_FAIL.ordinal()] = "Failed to decode the address type avp value for avp";
	pktLogs[LogPktEnum.PKT_SEND_KAFKA.ordinal()] = "Sending message to kafka on partition {}";
	pktLogs[LogPktEnum.PKT_KAFKA_EXCEPTION.ordinal()] = "Exception when sending to kafka {}";
	pktLogs[LogPktEnum.PKT_KAFKA_NOT_AVAILABLE.ordinal()] = "Kafka not available/reply partition not assigned";
	pktLogs[LogPktEnum.PKT_KAFKA_SEND_SUCCESS.ordinal()] = "Successfully sent message to kafka";
	pktLogs[LogPktEnum.PKT_KAFKA_SEND_STATE_MISMATCH.ordinal()] = "Successfully sent message to kafka , Transaction state doesn't match transID";
	pktLogs[LogPktEnum.PKT_HAUD_RESP_RCVD.ordinal()] = "Message received from kafka response topic";
	pktLogs[LogPktEnum.PKT_HAUD_RESP_FLTR_BYPASS.ordinal()] = "Haud response received with action ALLOW/FILTER_BYPASSED, fowarding diameter message";
	pktLogs[LogPktEnum.PKT_HAUD_RESP_BLK_SILENT.ordinal()] = "Haud response received with action BLOCK_SILENT, discarding the diameter message...!";
	pktLogs[LogPktEnum.PKT_HAUD_RESP_BLK_WITH_ERROR.ordinal()] = "Haud response received action BLOCK_WITH_ERROR, Sending Error response with error : {}";
	pktLogs[LogPktEnum.PKT_HAUD_RESP_BLK_WITH_ERROR_RESP.ordinal()] = "Haud response received action BLOCK_WITH_ERROR for diameter response message, discarding..!";
	pktLogs[LogPktEnum.PKT_HAUD_RESP_MIRROR.ordinal()] = "Haud response received with action MIRROR, sending message to originator";
	pktLogs[LogPktEnum.PKT_HAUD_RESP_DEFAULT.ordinal()] = "Haud response received with action Unknown, dropping the message....!";
	pktLogs[LogPktEnum.PKT_HAUD_RESP_TRANS_STATE_MISMATCH.ordinal()] = "Haud response received, Transaction state doesn't match. Discarding!";

	pktLogs[LogPktEnum.PKT_DEFAULT_ACTION.ordinal()] = "Handle default configured action";
	pktLogs[LogPktEnum.PKT_DEFAULT_DROP.ordinal()] = "com.haud.ap.mpm.MessageProcessingModule.handleConfiguredAction()  ==> DROPPED";
	pktLogs[LogPktEnum.PKT_DEFAULT_FORWARD.ordinal()] = "com.haud.ap.mpm.MessageProcessingModule.handleConfiguredAction()  ==> FORWARD";
	pktLogs[LogPktEnum.PKT_DEFAULT_RESP_ERROR.ordinal()] = "com.haud.ap.mpm.MessageProcessingModule.handleConfiguredAction()  ==> RESPOND_ERROR";
	pktLogs[LogPktEnum.PKT_DEFAULT_RESP_ERROR_FAIL.ordinal()] = "Default Action RESPOND_ERROR for diameter answer message..  dropping message";
	pktLogs[LogPktEnum.PKT_DEFAULT_UNKNOWN.ordinal()] = "Unknown default action configured...!";

	pktLogs[LogPktEnum.PKT_FAILOVER_MSG.ordinal()] = "Handle failover message transactionId {}";
	pktLogs[LogPktEnum.PKT_FAILOVER_MSG_ERROR.ordinal()] = "AP instance ID is same, Not proceeding with Failver.. Discarding the message!";
	pktLogs[LogPktEnum.PKT_FAILOVER_MSG_TIMEOUT.ordinal()] = "Received haud response, Transaction timed Out.. Discarding!";
	pktLogs[LogPktEnum.PKT_FAILOVER_MSG_REQ_FRM_KAFKA.ordinal()] = "Fetch message from REQ topic from partition, offset : {}";
	pktLogs[LogPktEnum.PKT_FAILOVER_TUNNEL_NO_CER.ordinal()] = "CER/CEA message is not exchanged on the tunnel, discarding the message...!";
	pktLogs[LogPktEnum.PKT_FAILOVER_TUNNEL_NOT_FOUND.ordinal()] = "Tunnel not found : {} ";
	pktLogs[LogPktEnum.PKT_FAILOVER_TUNNEL_NOT_UP.ordinal()] = "Tunnel is not UP, discarding the message....!";
	pktLogs[LogPktEnum.PKT_FAILOVER_TUNNEL_PEER_NOT_FOUND.ordinal()] = "Transport instance not found for ip:port {}";

	pktLogs[LogPktEnum.PKT_PCAP_RULE_MATCHED.ordinal()] = "PCAP rule matched for ruleID: {}";

    }
}

