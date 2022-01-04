
import re
import pandas as pd

parsedData = []
def checkInstrumentType(tokens, row):
    print("parsing Instrument type ", tokens[1])

def parseSeq(tokens, row):
    row['seq'] = tokens[1]
    print("parsing seq ", tokens[1]) 

def parseSource(tokens, row):
    row['source'] = tokens[1]
    print("parsing source ", tokens[1])

def parseMasterId(tokens, row):
    row['MasterId'] = tokens[1]
    print("parsing MasterId ", tokens[1])

def parseId(tokens, row):
    row['id'] = tokens[1]
    print("parsing Id ", tokens[1])

def parseRefType(tokens, row):
    print("parsing RefType ", tokens[1])


def parse(filepath):
    with open(filepath, 'r') as file_object:
        line = file_object.readline()
        while line:
            line = line.strip()
            # if (len(line) == 0):
            #     line = file_object.readline()
            #     continue
            m = re.findall('\[(.*?)\]', line)
            row = {
                'seq':0,
                'source':0,
                'MasterId':0,
                'id':0,
                'ric':0,
                'instrument_type':0   # 0 - instrument update, 1- instrument suppl update
                }
            for i in range(len(m)):
                if(i==0):
                    checkInstrumentType(m[i], row)
                    continue
                tokens = m[i].split("=")
                if (tokens[0] == "seq"):
                    parseSeq(tokens, row)
                elif (tokens[0] == "source"):
                    parseSource(tokens, row)
                elif (tokens[0] == "MasterId"):
                    parseMasterId(tokens, row)
                elif (tokens[0] == "id"):
                    parseId(tokens, row)
                elif (tokens[0] == "reftype"):
                    parseRefType(tokens, row)
                else:
                    print(m[i])
            parsedData.append(row)
            line = file_object.readline()
    data = pd.DataFrame(parsedData)      # map[masterId]
    data.set_index(['seq', 'source', 'MasterId'], inplace=True)
    return data


if __name__ == '__main__':
    filepath = 'sample.txt'
    data = parse(filepath)
    print(data)