

  (def flavors1 ["Vanilla" "Chocolate" "Cherry-Ripple"])

  (def flavors2 ["Lemon" "Butterscotch" "Licorice-Ripple"])

  (def all-flavors (concat flavors1 flavors2))

  (defn -main []
    (println "Two Lists Results: ")
    (println
      (filter
        #(= (first %) "Chocolate") ; The 1 for the parameter number indicator (%) is not needed since there is only one parameter.
        (cartesian-product flavors1 flavors2)))
    (newline)
    (println "Single List Results: ")
    (println
       (filter
         #(or (= (first %) "Chocolate") (= (last %) "Chocolate"))
        (cartesian-product all-flavors all-flavors))))

  (-main)