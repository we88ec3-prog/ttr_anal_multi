
void FUN_007510f0(int param_1,int param_2)

{
  int *piVar1;
  int in_EAX;
  
  if ((0 < param_1) && (0 < param_2)) {
    (**(code **)(**(int **)(in_EAX + 0x1c) + 0x104))(*(int **)(in_EAX + 0x1c),0);
    *(undefined4 *)(in_EAX + 0x1524) = 0xbf000000;
    *(float *)(in_EAX + 0x1528) = (float)param_2 - 0.5;
    *(undefined4 *)(in_EAX + 0x152c) = 0;
    *(float *)(in_EAX + 0x1540) = (float)param_1 - 0.5;
    *(float *)(in_EAX + 0x1544) = (float)param_2 - 0.5;
    *(undefined4 *)(in_EAX + 0x1548) = 0;
    *(undefined4 *)(in_EAX + 0x155c) = 0xbf000000;
    *(undefined4 *)(in_EAX + 0x1560) = 0xbf000000;
    *(undefined4 *)(in_EAX + 0x1564) = 0;
    *(float *)(in_EAX + 0x1578) = (float)param_1 - 0.5;
    *(undefined4 *)(in_EAX + 0x157c) = 0xbf000000;
    *(undefined4 *)(in_EAX + 0x1580) = 0;
    *(undefined4 *)(in_EAX + 0x1538) = 0;
    *(undefined4 *)(in_EAX + 0x153c) = 0x3f800000;
    *(undefined4 *)(in_EAX + 0x1554) = 0x3f800000;
    *(undefined4 *)(in_EAX + 0x1558) = 0x3f800000;
    *(undefined4 *)(in_EAX + 0x158c) = 0x3f800000;
    *(undefined4 *)(in_EAX + 0x1570) = 0;
    *(undefined4 *)(in_EAX + 0x1574) = 0;
    *(undefined4 *)(in_EAX + 0x1590) = 0;
    FUN_00753930((undefined4 *)(in_EAX + 0x1524));
    piVar1 = *(int **)(in_EAX + 0x1c);
    (**(code **)(*piVar1 + 400))(piVar1,0,*(undefined4 *)(in_EAX + 0x1598),0,0x1c);
    (**(code **)(*piVar1 + 0x164))(piVar1,0x144);
    (**(code **)(*piVar1 + 0x144))(piVar1,5,0,2);
    (**(code **)(**(int **)(in_EAX + 0x1c) + 0x104))(*(int **)(in_EAX + 0x1c),0,0);
  }
  return;
}

