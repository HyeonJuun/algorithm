SELECT ID, (SELECT COUNT(*) FROM ECOLI_DATA WHERE ED.ID = PARENT_ID )AS CHILD_COUNT
FROM ECOLI_DATA ED
ORDER BY ID