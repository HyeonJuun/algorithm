-- 코드를 입력하세요
SELECT U.USER_ID, U.NICKNAME, SUM(N.PRICE) AS TOTAL_SALES
FROM USED_GOODS_USER U
JOIN USED_GOODS_BOARD N ON U.USER_ID = N.WRITER_ID
WHERE N.STATUS = 'DONE'
GROUP BY U.USER_ID
HAVING TOTAL_SALES >= 700000
ORDER BY TOTAL_SALES 

# SELECT B.USER_ID, B.NICKNAME, SUM(A.PRICE) AS TOTAL_SALES 
# FROM USED_GOODS_BOARD A
# JOIN USED_GOODS_USER B ON A.WRITER_ID = B.USER_ID
# WHERE A.STATUS = 'DONE'
# GROUP BY B.USER_ID
# HAVING TOTAL_SALES >= 700000
# ORDER BY TOTAL_SALES
# (SELECT * FROM USED_GOODS_BOARD WHERE STATUS = 'DONE' GROUP BY WRITER_ID)

# SELECT D.WRITER_ID, SUM(PRICE) AS TOTAL_SALES 
# FROM (SELECT * FROM USED_GOODS_BOARD WHERE STATUS = 'DONE') D
# GROUP BY D.WRITER_ID 
# HAVING TOTAL_SALES >= 70000
# ORDER BY TOTAL_SALES