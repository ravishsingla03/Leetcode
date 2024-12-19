# Write your MySQL query statement below
Select w1.id from weather as w1
join weather as w2 
where w1.temperature > w2.temperature AND DATEDIFF(w1.recordDate,w2.recordDate)=1