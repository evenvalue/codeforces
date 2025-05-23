cmake_minimum_required(VERSION 3.17)
project(codeforces)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS_DEBUG "-DLOCAL ${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -pedantic -std=c++20 -Wformat=2 -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector")

# Codeforces Problemset
add_executable(1000F 1000F.cpp)
add_executable(1020A 1020A.cpp)
add_executable(1020B 1020B.cpp)
add_executable(1023A 1023A.cpp)
add_executable(1029B 1029B.cpp)
add_executable(1032C 1032C.cpp)
add_executable(103B 103B.cpp)
add_executable(1040B 1040B.cpp)
add_executable(1042B 1042B.cpp)
add_executable(1043B 1043B.cpp)
add_executable(1051D 1051D.cpp)
add_executable(1059A 1059A.cpp)
add_executable(1091C 1091C.cpp)
add_executable(1095F 1095F.cpp)
add_executable(1096D 1096D.cpp)
add_executable(1097B 1097B.cpp)
add_executable(1103A 1103A.cpp)
add_executable(1106D 1106D.cpp)
add_executable(1108D 1108D.cpp)
add_executable(1108F 1108F.cpp)
add_executable(1117B 1117B.cpp)
add_executable(1132F 1132F.cpp)
add_executable(1133E 1133E.cpp)
add_executable(1139C 1139C.cpp)
add_executable(1140D 1140D.cpp)
add_executable(1141D 1141D.cpp)
add_executable(1143C 1143C.cpp)
add_executable(1144F 1144F.cpp)
add_executable(1144G 1144G.cpp)
add_executable(1154A 1154A.cpp)
add_executable(1156A 1156A.cpp)
add_executable(115A 115A.cpp)
add_executable(1162B 1162B.cpp)
add_executable(1167B 1167B.cpp)
add_executable(1176C 1176C.cpp)
add_executable(1178B 1178B.cpp)
add_executable(1182B 1182B.cpp)
add_executable(1183D 1183D.cpp)
add_executable(1187D 1187D.cpp)
add_executable(1187E 1187E.cpp)
add_executable(1188C 1188C.cpp)
add_executable(1189C 1189C.cpp)
add_executable(118B 118B.cpp)
add_executable(118D 118D.cpp)
add_executable(1200C 1200C.cpp)
add_executable(1208B 1208B.cpp)
add_executable(120F 120F.cpp)
add_executable(1213B 1213B.cpp)
add_executable(1213G 1213G.cpp)
add_executable(1215B 1215B.cpp)
add_executable(1220A 1220A.cpp)
add_executable(1220B 1220B.cpp)
add_executable(1221D 1221D.cpp)
add_executable(1234C 1234C.cpp)
add_executable(1234D 1234D.cpp)
add_executable(1238D 1238D.cpp)
add_executable(1238E 1238E.cpp)
add_executable(1245B 1245B.cpp)
add_executable(1245C 1245C.cpp)
add_executable(1249E 1249E.cpp)
add_executable(1250F 1250F.cpp)
add_executable(1251E1 1251E1.cpp)
add_executable(1251E2 1251E2.cpp)
add_executable(1253B 1253B.cpp)
add_executable(1253C 1253C.cpp)
add_executable(1253F 1253F.cpp)
add_executable(1254D 1254D.cpp)
add_executable(1260E 1260E.cpp)
add_executable(1263C 1263C.cpp)
add_executable(1263D 1263D.cpp)
add_executable(1266C 1266C.cpp)
add_executable(1268B 1268B.cpp)
add_executable(1272C 1272C.cpp)
add_executable(1276A 1276A.cpp)
add_executable(1282B2 1282B2.cpp)
add_executable(1282D 1282D.cpp)
add_executable(1284B 1284B.cpp)
add_executable(1284D 1284D.cpp)
add_executable(1285C 1285C.cpp)
add_executable(1288B 1288B.cpp)
add_executable(1288D 1288D.cpp)
add_executable(128C 128C.cpp)
add_executable(1294A 1294A.cpp)
add_executable(1294C 1294C.cpp)
add_executable(1294F 1294F.cpp)
add_executable(1295C 1295C.cpp)
add_executable(1299A 1299A.cpp)
add_executable(1304C 1304C.cpp)
add_executable(1312C 1312C.cpp)
add_executable(1315B 1315B.cpp)
add_executable(1320A 1320A.cpp)
add_executable(1324C 1324C.cpp)
add_executable(1324D 1324D.cpp)
add_executable(1324E 1324E.cpp)
add_executable(1325C 1325C.cpp)
add_executable(1325F 1325F.cpp)
add_executable(1327B 1327B.cpp)
add_executable(1327E 1327E.cpp)
add_executable(1328A 1328A.cpp)
add_executable(1328B 1328B.cpp)
add_executable(1328D 1328D.cpp)
add_executable(132C 132C.cpp)
add_executable(1332B 1332B.cpp)
add_executable(1332C 1332C.cpp)
add_executable(1335D 1335D.cpp)
add_executable(1335E1 1335E1.cpp)
add_executable(1335E2 1335E2.cpp)
add_executable(1338A 1338A.cpp)
add_executable(1343C 1343C.cpp)
add_executable(1344B 1344B.cpp)
add_executable(1348A 1348A.cpp)
add_executable(1348E 1348E.cpp)
add_executable(1349B 1349B.cpp)
add_executable(1354B 1354B.cpp)
add_executable(1354C1 1354C1.cpp)
add_executable(1358E 1358E.cpp)
add_executable(1359D 1359D.cpp)
add_executable(1360F 1360F.cpp)
add_executable(1363B 1363B.cpp)
add_executable(1363D 1363D.cpp)
add_executable(1363E 1363E.cpp)
add_executable(1365C 1365C.cpp)
add_executable(1365D 1365D.cpp)
add_executable(1366D 1366D.cpp)
add_executable(1368B 1368B.cpp)
add_executable(1370A 1370A.cpp)
add_executable(1370D 1370D.cpp)
add_executable(1370F1 1370F1.cpp)
add_executable(1373D 1373D.cpp)
add_executable(1374C 1374C.cpp)
add_executable(1374D 1374D.cpp)
add_executable(1375C 1375C.cpp)
add_executable(1375E 1375E.cpp)
add_executable(1375F 1375F.cpp)
add_executable(1379C 1379C.cpp)
add_executable(1381B 1381B.cpp)
add_executable(1385A 1385A.cpp)
add_executable(1385E 1385E.cpp)
add_executable(1388D 1388D.cpp)
add_executable(1389B 1389B.cpp)
add_executable(1389C 1389C.cpp)
add_executable(1391C 1391C.cpp)
add_executable(1391D 1391D.cpp)
add_executable(1392F 1392F.cpp)
add_executable(1395C 1395C.cpp)
add_executable(1398C 1398C.cpp)
add_executable(1398D 1398D.cpp)
add_executable(1399E1 1399E1.cpp)
add_executable(13E 13E.cpp)
add_executable(1404A 1404A.cpp)
add_executable(1407C 1407C.cpp)
add_executable(1407E 1407E.cpp)
add_executable(1413B 1413B.cpp)
add_executable(1415C 1415C.cpp)
add_executable(1415D 1415D.cpp)
add_executable(1416D 1416D.cpp)
add_executable(1417E 1417E.cpp)
add_executable(1418C 1418C.cpp)
add_executable(1422D 1422D.cpp)
add_executable(1427C 1427C.cpp)
add_executable(1426F 1426F.cpp)
add_executable(1436E 1436E.cpp)
add_executable(1438C 1438C.cpp)
add_executable(1443B 1443B.cpp)
add_executable(1446B 1446B.cpp)
add_executable(1451C 1451C.cpp)
add_executable(1452A 1452A.cpp)
add_executable(1452D 1452D.cpp)
add_executable(1453B 1453B.cpp)
add_executable(1454D 1454D.cpp)
add_executable(1454E 1454E.cpp)
add_executable(1455C 1455C.cpp)
add_executable(1455D 1455D.cpp)
add_executable(1459B 1459B.cpp)
add_executable(145E 145E.cpp)
add_executable(1461B 1461B.cpp)
add_executable(1463E 1463E.cpp)
add_executable(1466C 1466C.cpp)
add_executable(1466D 1466D.cpp)
add_executable(1468C 1468C.cpp)
add_executable(1473D 1473D.cpp)
add_executable(1476E 1476E.cpp)
add_executable(1479A 1479A.cpp)
add_executable(1482F 1482F.cpp)
add_executable(1485D 1485D.cpp)
add_executable(1485E 1485E.cpp)
add_executable(1485F 1485F.cpp)
add_executable(1486B 1486B.cpp)
add_executable(1487A 1487A.cpp)
add_executable(1487C 1487C.cpp)
add_executable(1490E 1490E.cpp)
add_executable(1492A 1492A.cpp)
add_executable(1492B 1492B.cpp)
add_executable(1492C 1492C.cpp)
add_executable(1493B 1493B.cpp)
add_executable(1494A 1494A.cpp)
add_executable(1494B 1494B.cpp)
add_executable(1494C 1494C.cpp)
add_executable(1494D 1494D.cpp)
add_executable(1494E 1494E.cpp)
add_executable(1505A 1505A.cpp)
add_executable(1506B 1506B.cpp)
add_executable(1506D 1506D.cpp)
add_executable(1508C 1508C.cpp)
add_executable(150A 150A.cpp)
add_executable(1513B 1513B.cpp)
add_executable(1516B 1516B.cpp)
add_executable(1519A 1519A.cpp)
add_executable(1519C 1519C.cpp)
add_executable(1519D 1519D.cpp)
add_executable(1520A 1520A.cpp)
add_executable(1520B 1520B.cpp)
add_executable(1520C 1520C.cpp)
add_executable(1520D 1520D.cpp)
add_executable(1520E 1520E.cpp)
add_executable(1520F1 1520F1.cpp)
add_executable(1521A 1521A.cpp)
add_executable(1521B 1521B.cpp)
add_executable(1521D 1521D.cpp)
add_executable(1523A 1523A.cpp)
add_executable(1523B 1523B.cpp)
add_executable(1523C 1523C.cpp)
add_executable(1526C1 1526C1.cpp)
add_executable(1526C2 1526C2.cpp)
add_executable(1527E 1527E.cpp)
add_executable(1529A 1529A.cpp)
add_executable(1529B 1529B.cpp)
add_executable(1529C 1529C.cpp)
add_executable(1530A 1530A.cpp)
add_executable(1530B 1530B.cpp)
add_executable(1530C 1530C.cpp)
add_executable(1531A 1531A.cpp)
add_executable(1534A 1534A.cpp)
add_executable(1534B 1534B.cpp)
add_executable(1534C 1534C.cpp)
add_executable(1534D 1534D.cpp)
add_executable(1534E 1534E.cpp)
add_executable(1536B 1536B.cpp)
add_executable(1536C 1536C.cpp)
add_executable(1537A 1537A.cpp)
add_executable(1537B 1537B.cpp)
add_executable(1538A 1538A.cpp)
add_executable(1538B 1538B.cpp)
add_executable(1538C 1538C.cpp)
add_executable(1538D 1538D.cpp)
add_executable(1538E 1538E.cpp)
add_executable(1538F 1538F.cpp)
add_executable(1539A 1539A.cpp)
add_executable(1540A 1540A.cpp)
add_executable(1540B 1540B.cpp)
add_executable(1541A 1541A.cpp)
add_executable(1541B 1541B.cpp)
add_executable(1542B 1542B.cpp)
add_executable(1543A 1543A.cpp)
add_executable(1543B 1543B.cpp)
add_executable(1545A 1545A.cpp)
add_executable(1546A 1546A.cpp)
add_executable(1546B 1546B.cpp)
add_executable(1547A 1547A.cpp)
add_executable(1547B 1547B.cpp)
add_executable(1547C 1547C.cpp)
add_executable(1547D 1547D.cpp)
add_executable(1547E 1547E.cpp)
add_executable(1547F 1547F.cpp)
add_executable(1549A 1549A.cpp)
add_executable(1549B 1549B.cpp)
add_executable(1549C 1549C.cpp)
add_executable(1549D 1549D.cpp)
add_executable(1550B 1550B.cpp)
add_executable(1551A 1551A.cpp)
add_executable(1551B1 1551B1.cpp)
add_executable(1551B2 1551B2.cpp)
add_executable(1551C 1551C.cpp)
add_executable(1551D1 1551D1.cpp)
add_executable(1553A 1553A.cpp)
add_executable(1553B 1553B.cpp)
add_executable(1553C 1553C.cpp)
add_executable(1553D 1553D.cpp)
add_executable(1554A 1554A.cpp)
add_executable(1554E 1554E.cpp)
add_executable(1555A 1555A.cpp)
add_executable(1557A 1557A.cpp)
add_executable(1557B 1557B.cpp)
add_executable(1559A 1559A.cpp)
add_executable(1559B 1559B.cpp)
add_executable(1559C 1559C.cpp)
add_executable(1559D1 1559D1.cpp)
add_executable(1559D2 1559D2.cpp)
add_executable(1559E 1559E.cpp)
add_executable(1561A 1561A.cpp)
add_executable(1561B 1561B.cpp)
add_executable(1561C 1561C.cpp)
add_executable(1566A 1566A.cpp)
add_executable(1566B 1566B.cpp)
add_executable(1566C 1566C.cpp)
add_executable(1566D1 1566D1.cpp)
add_executable(1567A 1567A.cpp)
add_executable(1567B 1567B.cpp)
add_executable(1567C 1567C.cpp)
add_executable(1569A 1569A.cpp)
add_executable(1569B 1569B.cpp)
add_executable(156C 156C.cpp)
add_executable(1574A 1574A.cpp)
add_executable(1574B 1574B.cpp)
add_executable(1574C 1574C.cpp)
add_executable(1574D 1574D.cpp)
add_executable(1575J 1575J.cpp)
add_executable(1579A 1579A.cpp)
add_executable(1579B 1579B.cpp)
add_executable(1579C 1579C.cpp)
add_executable(1579D 1579D.cpp)
add_executable(1579E1 1579E1.cpp)
add_executable(1582F1 1582F1.cpp)
add_executable(1582F2 1582F2.cpp)
add_executable(1592A 1592A.cpp)
add_executable(1592B 1592B.cpp)
add_executable(1592D 1592D.cpp)
add_executable(1593A 1593A.cpp)
add_executable(1593B 1593B.cpp)
add_executable(1593C 1593C.cpp)
add_executable(1593D1 1593D1.cpp)
add_executable(1593E 1593E.cpp)
add_executable(1594A 1594A.cpp)
add_executable(1594B 1594B.cpp)
add_executable(1594C 1594C.cpp)
add_executable(1594D 1594D.cpp)
add_executable(1594E1 1594E1.cpp)
add_executable(1598A 1598A.cpp)
add_executable(1598B 1598B.cpp)
add_executable(1598C 1598C.cpp)
add_executable(1598D 1598D.cpp)
add_executable(1602A 1602A.cpp)
add_executable(1602B 1602B.cpp)
add_executable(1602C 1602C.cpp)
add_executable(1606C 1606C.cpp)
add_executable(1607F 1607F.cpp)
add_executable(1609E 1609E.cpp)
add_executable(1615E 1615E.cpp)
add_executable(1618F 1618F.cpp)
add_executable(161D 161D.cpp)
add_executable(1624E 1624E.cpp)
add_executable(1628C 1628C.cpp)
add_executable(1631A 1631A.cpp)
add_executable(1634E 1634E.cpp)
add_executable(1649A 1649A.cpp)
add_executable(1654A 1654A.cpp)
add_executable(1654B 1654B.cpp)
add_executable(1654C 1654C.cpp)
add_executable(165C 165C.cpp)
add_executable(165E 165E.cpp)
add_executable(166E 166E.cpp)
add_executable(1671A 1671A.cpp)
add_executable(1671B 1671B.cpp)
add_executable(1671C 1671C.cpp)
add_executable(1672E 1672E.cpp)
add_executable(1674E 1674E.cpp)
add_executable(1682D 1682D.cpp)
add_executable(1693C 1693C.cpp)
add_executable(1706E 1706E.cpp)
add_executable(1715E 1715E.cpp)
add_executable(1763E 1763E.cpp)
add_executable(1764D 1764D.cpp)
add_executable(1772G 1772G.cpp)
add_executable(1777F 1777F.cpp)
add_executable(1779E 1779E.cpp)
add_executable(17B 17B.cpp)
add_executable(1804A 1804A.cpp)
add_executable(1804B 1804B.cpp)
add_executable(1804C 1804C.cpp)
add_executable(1804D 1804D.cpp)
add_executable(1804E 1804E.cpp)
add_executable(180E 180E.cpp)
add_executable(1826E 1826E.cpp)
add_executable(1832D1 1832D1.cpp)
add_executable(1832D2 1832D2.cpp)
add_executable(1837F 1837F.cpp)
add_executable(1854A1 1854A1.cpp)
add_executable(1854A2 1854A2.cpp)
add_executable(1854B 1854B.cpp)
add_executable(1857G 1857G.cpp)
add_executable(1859E 1859E.cpp)
add_executable(1872G 1872G.cpp)
add_executable(1874B 1874B.cpp)
add_executable(1879E 1879E.cpp)
add_executable(1901E 1901E.cpp)
add_executable(1904E 1904E.cpp)
add_executable(1905A 1905A.cpp)
add_executable(1905B 1905B.cpp)
add_executable(1905C 1905C.cpp)
add_executable(1905D 1905D.cpp)
add_executable(1905E 1905E.cpp)
add_executable(1905F 1905F.cpp)
add_executable(1909A 1909A.cpp)
add_executable(1909B 1909B.cpp)
add_executable(1909C 1909C.cpp)
add_executable(1909D 1909D.cpp)
add_executable(1909E 1909E.cpp)
add_executable(1916A 1916A.cpp)
add_executable(1916B 1916B.cpp)
add_executable(1916C 1916C.cpp)
add_executable(1916D 1916D.cpp)
add_executable(1916E 1916E.cpp)
add_executable(1918A 1918A.cpp)
add_executable(1918B 1918B.cpp)
add_executable(1918C 1918C.cpp)
add_executable(1918D 1918D.cpp)
add_executable(1918E 1918E.cpp)
add_executable(1918F 1918F.cpp)
add_executable(1919A 1919A.cpp)
add_executable(1919B 1919B.cpp)
add_executable(1919C 1919C.cpp)
add_executable(1919D 1919D.cpp)
add_executable(1919E 1919E.cpp)
add_executable(1919F1 1919F1.cpp)
add_executable(1919F2 1919F2.cpp)
add_executable(1929A 1929A.cpp)
add_executable(1929B 1929B.cpp)
add_executable(1929C 1929C.cpp)
add_executable(1929D 1929D.cpp)
add_executable(1929F 1929F.cpp)
add_executable(1934D2 1934D2.cpp)
add_executable(1936A 1936A.cpp)
add_executable(1936B 1936B.cpp)
add_executable(1936C 1936C.cpp)
add_executable(1946F 1946F.cpp)
add_executable(1965A 1965A.cpp)
add_executable(1965B 1965B.cpp)
add_executable(1967A 1967A.cpp)
add_executable(1967B1 1967B1.cpp)
add_executable(1967C 1967C.cpp)
add_executable(1969A 1969A.cpp)
add_executable(1969B 1969B.cpp)
add_executable(1969C 1969C.cpp)
add_executable(1969D 1969D.cpp)
add_executable(1969E 1969E.cpp)
add_executable(1980G 1980G.cpp)
add_executable(1982F 1982F.cpp)
add_executable(1983A 1983A.cpp)
add_executable(1983B 1983B.cpp)
add_executable(1983C 1983C.cpp)
add_executable(1983D 1983D.cpp)
add_executable(1983E 1983E.cpp)
add_executable(1983F 1983F.cpp)
add_executable(2022E1 2022E1.cpp)
add_executable(2022E2 2022E2.cpp)
add_executable(2023A 2023A.cpp)
add_executable(2023B 2023B.cpp)
add_executable(2023C 2023C.cpp)
add_executable(2030F 2030F.cpp)
add_executable(2042F 2042F.cpp)
add_executable(20A 20A.cpp)
add_executable(20C 20C.cpp)
add_executable(217A 217A.cpp)
add_executable(220B 220B.cpp)
add_executable(234C 234C.cpp)
add_executable(242A 242A.cpp)
add_executable(245H 245H.cpp)
add_executable(253B 253B.cpp)
add_executable(258C 258C.cpp)
add_executable(25D 25D.cpp)
add_executable(268A 268A.cpp)
add_executable(289B 289B.cpp)
add_executable(293E 293E.cpp)
add_executable(296B 296B.cpp)
add_executable(2B 2B.cpp)
add_executable(300B 300B.cpp)
add_executable(313B 313B.cpp)
add_executable(319C 319C.cpp)
add_executable(320B 320B.cpp)
add_executable(321C 321C.cpp)
add_executable(322B 322B.cpp)
add_executable(337D 337D.cpp)
add_executable(339D 339D.cpp)
add_executable(342E 342E.cpp)
add_executable(343D 343D.cpp)
add_executable(358D 358D.cpp)
add_executable(35D 35D.cpp)
add_executable(371D 371D.cpp)
add_executable(375D 375D.cpp)
add_executable(380C 380C.cpp)
add_executable(382A 382A.cpp)
add_executable(383C 383C.cpp)
add_executable(385C 385C.cpp)
add_executable(416B 416B.cpp)
add_executable(425A 425A.cpp)
add_executable(431C 431C.cpp)
add_executable(433B 433B.cpp)
add_executable(436B 436B.cpp)
add_executable(437C 437C.cpp)
add_executable(438D 438D.cpp)
add_executable(446A 446A.cpp)
add_executable(450B 450B.cpp)
add_executable(455A 455A.cpp)
add_executable(455B 455B.cpp)
add_executable(459D 459D.cpp)
add_executable(461B 461B.cpp)
add_executable(462A 462A.cpp)
add_executable(466C 466C.cpp)
add_executable(467B 467B.cpp)
add_executable(467C 467C.cpp)
add_executable(474D 474D.cpp)
add_executable(474F 474F.cpp)
add_executable(475B 475B.cpp)
add_executable(478D 478D.cpp)
add_executable(484D 484D.cpp)
add_executable(484E 484E.cpp)
add_executable(490A 490A.cpp)
add_executable(492C 492C.cpp)
add_executable(493B 493B.cpp)
add_executable(4A 4A.cpp)
add_executable(501B 501B.cpp)
add_executable(501C 501C.cpp)
add_executable(508D 508D.cpp)
add_executable(510C 510C.cpp)
add_executable(514B 514B.cpp)
add_executable(514C 514C.cpp)
add_executable(519E 519E.cpp)
add_executable(522A 522A.cpp)
add_executable(525A 525A.cpp)
add_executable(526B 526B.cpp)
add_executable(52C 52C.cpp)
add_executable(543A 543A.cpp)
add_executable(545C 545C.cpp)
add_executable(546D 546D.cpp)
add_executable(550A 550A.cpp)
add_executable(550C 550C.cpp)
add_executable(558E 558E.cpp)
add_executable(559C 559C.cpp)
add_executable(567C 567C.cpp)
add_executable(580A 580A.cpp)
add_executable(580B 580B.cpp)
add_executable(580C 580C.cpp)
add_executable(580D 580D.cpp)
add_executable(597C 597C.cpp)
add_executable(600E 600E.cpp)
add_executable(602B 602B.cpp)
add_executable(616D 616D.cpp)
add_executable(61E 61E.cpp)
add_executable(626B 626B.cpp)
add_executable(628B 628B.cpp)
add_executable(631E 631E.cpp)
add_executable(632E 632E.cpp)
add_executable(650A 650A.cpp)
add_executable(653B 653B.cpp)
add_executable(659D 659D.cpp)
add_executable(665C 665C.cpp)
add_executable(676C 676C.cpp)
add_executable(679A 679A.cpp)
add_executable(687A 687A.cpp)
add_executable(689E 689E.cpp)
add_executable(690C2 690C2.cpp)
add_executable(696A 696A.cpp)
add_executable(696C 696C.cpp)
add_executable(702B 702B.cpp)
add_executable(704B 704B.cpp)
add_executable(706C 706C.cpp)
add_executable(710B 710B.cpp)
add_executable(710C 710C.cpp)
add_executable(711C 711C.cpp)
add_executable(713C 713C.cpp)
add_executable(715B 715B.cpp)
add_executable(718C 718C.cpp)
add_executable(719B 719B.cpp)
add_executable(71A 71A.cpp)
add_executable(721C 721C.cpp)
add_executable(727C 727C.cpp)
add_executable(729B 729B.cpp)
add_executable(732F 732F.cpp)
add_executable(73C 73C.cpp)
add_executable(748F 748F.cpp)
add_executable(749A 749A.cpp)
add_executable(757B 757B.cpp)
add_executable(762A 762A.cpp)
add_executable(763A 763A.cpp)
add_executable(765C 765C.cpp)
add_executable(771A 771A.cpp)
add_executable(776D 776D.cpp)
add_executable(777B 777B.cpp)
add_executable(786B 786B.cpp)
add_executable(797E 797E.cpp)
add_executable(798B 798B.cpp)
add_executable(802J 802J.cpp)
add_executable(803A 803A.cpp)
add_executable(821C 821C.cpp)
add_executable(822A 822A.cpp)
add_executable(825E 825E.cpp)
add_executable(834D 834D.cpp)
add_executable(837G 837G.cpp)
add_executable(839C 839C.cpp)
add_executable(842C 842C.cpp)
add_executable(851B 851B.cpp)
add_executable(855B 855B.cpp)
add_executable(859C 859C.cpp)
add_executable(865D 865D.cpp)
add_executable(868F 868F.cpp)
add_executable(86D 86D.cpp)
add_executable(870C 870C.cpp)
add_executable(888G 888G.cpp)
add_executable(894B 894B.cpp)
add_executable(895C 895C.cpp)
add_executable(89A 89A.cpp)
add_executable(8B 8B.cpp)
add_executable(901A 901A.cpp)
add_executable(908C 908C.cpp)
add_executable(909C 909C.cpp)
add_executable(915E 915E.cpp)
add_executable(920C 920C.cpp)
add_executable(920E 920E.cpp)
add_executable(930A 930A.cpp)
add_executable(932F 932F.cpp)
add_executable(933A 933A.cpp)
add_executable(937B 937B.cpp)
add_executable(938D 938D.cpp)
add_executable(939A 939A.cpp)
add_executable(946D 946D.cpp)
add_executable(955B 955B.cpp)
add_executable(958D1 958D1.cpp)
add_executable(959B 959B.cpp)
add_executable(959C 959C.cpp)
add_executable(961B 961B.cpp)
add_executable(962C 962C.cpp)
add_executable(96A 96A.cpp)
add_executable(976D 976D.cpp)
add_executable(977E 977E.cpp)
add_executable(977F 977F.cpp)
add_executable(981C 981C.cpp)
add_executable(982C 982C.cpp)
add_executable(983B 983B.cpp)
add_executable(986C 986C.cpp)
add_executable(987C 987C.cpp)
add_executable(997B 997B.cpp)
add_executable(998B 998B.cpp)

# Codeforces Gym
add_executable(101021A 101021A.cpp)
add_executable(102576C 102576C.cpp)
add_executable(102644A 102644A.cpp)
add_executable(102644B 102644B.cpp)
add_executable(102644C 102644C.cpp)
add_executable(102644D 102644D.cpp)
add_executable(103091A 103091A.cpp)
add_executable(103536A 103536A.cpp)

# Codeforces Edu
add_executable(273169A 273169A.cpp)
add_executable(273169B 273169B.cpp)
add_executable(273169C 273169C.cpp)
add_executable(289390A 289390A.cpp)
add_executable(289390B 289390B.cpp)