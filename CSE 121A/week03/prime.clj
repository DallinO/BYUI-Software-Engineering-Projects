(defn is-prime [x]
(loop [n 2]
    (cond
        (< n x) (if (not= 0 (mod x n))
            (recur (inc n))
            false)
        :else true)))

       
(println "Variable 'x': ") (def x (read-string(read-line)))
(is-prime x)