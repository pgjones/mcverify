## Predicted Cerenkov yield
Predicts the Cerenkov yield for Electrons in light water ONLY.
Use in ROOT, .L CalculateCerenkovYield.cc+ then 

    double range;
    double yield = PredictedCerenkovYield( Energy, range );

The range parameter will be filled with the electron range.