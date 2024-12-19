# Write your MySQL query statement below
SELECT customer_id,count(*) as count_no_trans
From visits as v
LEFT JOIN transactions as t
ON v.visit_id = t.visit_id
where t.visit_id IS NULL
group by customer_id
