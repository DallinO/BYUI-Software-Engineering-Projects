(defn gcd [a b]
  (if (zero? b)
    a
    (do
     (println a '= b (list (quot a b)) '+ (rem a b))
     (recur b (mod a b)))))

(println "Variable 'a': ") (def a (read-string(read-line)))
(println "Variable 'b': ") (def b (read-string(read-line)))
(gcd a b)