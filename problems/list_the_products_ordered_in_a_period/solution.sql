SELECT P.product_name, TEMP.sUnit AS unit 
    FROM Products P 
    JOIN (SELECT product_id, sum(unit) AS sUnit 
            FROM Orders WHERE (order_date BETWEEN '2020-02-01' AND '2020-02-29') 
                GROUP BY product_id HAVING sUnit >= 100) 
                    AS TEMP ON P.product_id = TEMP.product_id; 