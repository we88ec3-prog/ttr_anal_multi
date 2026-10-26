
undefined4 FUN_00849bd0(undefined4 *param_1,int param_2)

{
  int in_ECX;
  undefined4 local_94 [4];
  undefined4 local_84;
  float local_7c;
  float local_78;
  float local_74;
  
  _memset(local_94,0,0x34);
  local_74 = 1.0;
  local_84 = 0x3f800000;
  local_94[0] = 0x3f800000;
  FUN_00780a00();
  switch(*(undefined4 *)(param_2 + 0x88)) {
  case 0:
    FUN_00849730(*(undefined4 *)(param_2 + 0x8c),*(undefined4 *)(param_2 + 0x90),
                 *(undefined4 *)(param_2 + 0x94),*param_1,param_1[1],param_1[2],-local_7c,-local_78,
                 -local_74,*(undefined4 *)(param_2 + 0x7c),*(undefined4 *)(param_2 + 0x78),
                 *(undefined4 *)(param_2 + 0x74));
    FUN_00849f20(in_ECX + 4);
    return 1;
  case 1:
    FUN_008497b0(*(undefined4 *)(param_2 + 0x8c),*(undefined4 *)(param_2 + 0x90),
                 *(undefined4 *)(param_2 + 0x94),-local_7c,-local_78,-local_74);
    FUN_0084a000(in_ECX + 0x34);
    return 1;
  case 2:
    FUN_00849800(*(undefined4 *)(param_2 + 0x8c),*(undefined4 *)(param_2 + 0x90),
                 *(undefined4 *)(param_2 + 0x94),*param_1,param_1[1],param_1[2],
                 *(undefined4 *)(param_2 + 0x74));
    FUN_00849f90(in_ECX + 0x14);
    return 1;
  case 3:
    FUN_007b1810();
    return 1;
  default:
    return 0;
  }
}

