(def alpha ["Vanilla" "Chocolate" "Cherry-Ripple"])
(def bravo ["Lemon" "Butterscotch" "Licorice-Ripple"])
(def conjoined (concat alpha bravo))
(defn -main []
  (println "Flavor List: Vanilla, Chocolate, Cherry-Ripple")
  (println "Enter Flavor List Location: ") (def x (read-string(read-line)))
  (println "Two Lists Results: ")
  (println
    (filter
      #(= (first %) (nth alpha x)) 
      (cartesian-product alpha bravo)))
  (newline)
  (println "Single List Results: ")
  (println
      (filter
        #(or (= (first %) (nth alpha x)) (= (last %) (nth alpha x)))
      (cartesian-product conjoined conjoined))))

(-main)