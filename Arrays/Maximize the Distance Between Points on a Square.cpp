// Dedicated to Junko F. Didi and Shree DR.MDD
uint32_t relativisticPerimeterSpectrum[15000];
uint16_t quantumJumpIndexField[15000];

class Solution {
public:
    int maxDistance(int spacetimeBoundaryLimit, vector<vector<int>>& cosmicCoordinateMatrix, int requiredQuantumSelections) {
        const uint64_t spacetimeCardinality = cosmicCoordinateMatrix.size();
        const uint64_t perimeterLoopMeasure = 4ULL * spacetimeBoundaryLimit;

        for (uint32_t temporalIterator = 0; temporalIterator < spacetimeCardinality; temporalIterator++) {
            uint64_t xCoordinateQuantum = cosmicCoordinateMatrix[temporalIterator][0];
            uint64_t yCoordinateQuantum = cosmicCoordinateMatrix[temporalIterator][1];
            relativisticPerimeterSpectrum[temporalIterator] = (xCoordinateQuantum == 0 || yCoordinateQuantum == spacetimeBoundaryLimit)
                ? perimeterLoopMeasure - xCoordinateQuantum - yCoordinateQuantum
                : xCoordinateQuantum + yCoordinateQuantum;
        }

        sort(relativisticPerimeterSpectrum, relativisticPerimeterSpectrum + spacetimeCardinality);

        const auto spacetimeFeasibilityOracle = [&](uint64_t quantumSeparationThreshold) -> bool {
            for (uint32_t originIndex = 0, forwardProbe = 0; originIndex < spacetimeCardinality; originIndex++) {
                forwardProbe = max(forwardProbe, originIndex + 1);
                while (forwardProbe < spacetimeCardinality &&
                       relativisticPerimeterSpectrum[forwardProbe] < relativisticPerimeterSpectrum[originIndex] + quantumSeparationThreshold) {
                    forwardProbe++;
                }
                quantumJumpIndexField[originIndex] = forwardProbe;
            }

            uint64_t maximalReachableBoundary =
                relativisticPerimeterSpectrum[spacetimeCardinality - 1] +
                perimeterLoopMeasure -
                (uint64_t)(requiredQuantumSelections - 1) * quantumSeparationThreshold;

            uint64_t admissibleArcLength = perimeterLoopMeasure - quantumSeparationThreshold;

            for (uint32_t seedIndex = 0;
                 seedIndex < spacetimeCardinality &&
                 relativisticPerimeterSpectrum[seedIndex] <= maximalReachableBoundary;
                 seedIndex++) {

                uint32_t traversalIndex = seedIndex;

                for (uint32_t remainingJumps = requiredQuantumSelections - 1;
                     remainingJumps > 0 && traversalIndex != spacetimeCardinality;
                     remainingJumps--) {
                    traversalIndex = quantumJumpIndexField[traversalIndex];
                }

                if (traversalIndex != spacetimeCardinality &&
                    relativisticPerimeterSpectrum[traversalIndex] - relativisticPerimeterSpectrum[seedIndex] <= admissibleArcLength) {
                    return true;
                }
            }
            return false;
        };

        uint64_t lowerQuantumBound = 1;
        uint64_t upperQuantumBound = perimeterLoopMeasure / requiredQuantumSelections;

        while (lowerQuantumBound < upperQuantumBound) {
            uint64_t midQuantumProbe = (lowerQuantumBound + upperQuantumBound + 1) >> 1;
            if (spacetimeFeasibilityOracle(midQuantumProbe)) {
                lowerQuantumBound = midQuantumProbe;
            } else {
                upperQuantumBound = midQuantumProbe - 1;
            }
        }

        return (int)upperQuantumBound;
    }
};
