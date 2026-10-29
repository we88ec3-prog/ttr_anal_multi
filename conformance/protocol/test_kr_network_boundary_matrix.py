"""Offline evidence-matrix integrity checks, NOT runtime/TCP conformance tests."""
import json
import unittest
from pathlib import Path
DATA=json.loads(Path(__file__).with_name("kr-network-boundary-matrix.json").read_text(encoding="utf-8"))
class NetworkBoundaryMatrix(unittest.TestCase):
    def test_known_connect_calls_are_distinct_roles(self):
        self.assertEqual(DATA["provenance"],"STATIC_SOURCE_DERIVED")
        self.assertEqual(
            [(row["tcp_port"],row["slot"],row["pipeline"]) for row in DATA["connect_calls"]],
            [(8415,1,2),(8416,0,2),(8414,2,2)])
        self.assertEqual({row["pipeline"] for row in DATA["connect_calls"]},{2})
        self.assertEqual({row["slot"] for row in DATA["connect_calls"]},{0,1,2})
    def test_outbound_chain_reaches_api_but_does_not_prove_ack(self):
        self.assertEqual(DATA["outbound_stages"],[
            "0x8069A0","0x8060D0","0x806060","0x8061A0","0x804A40","0x8068B0","WSASend"])
        self.assertIn("not Server compatibility",DATA["qualification"])
    def test_recv_dispatch_and_business_namespace_separated(self):
        self.assertEqual(DATA["inbound_stages"][-2:],
                         ["0x4930E0","CClient/Scene dispatch"])
        self.assertIn("channel==2",DATA["observed_command_index_layer"])
        self.assertIn("0x0BBB",DATA["frame_discriminators_are_not_business_opcodes"])
        self.assertIn("initial S2C marker selection",DATA["unresolved"])
if __name__=="__main__":unittest.main()
