
void FUN_007130f0(int *param_1,int *param_2)

{
  uint *puVar1;
  undefined4 in_EAX;
  int *in_ECX;
  
  switch(in_EAX) {
  case 0:
    FUN_00712ea0(0xc,param_1,param_2);
    return;
  case 1:
    FUN_00712ea0(0xd,param_1,param_2);
    return;
  case 2:
    FUN_00712ea0(0xe,param_1,param_2);
    return;
  case 3:
    FUN_00712ea0(0xf,param_1,param_2);
    return;
  case 4:
    FUN_00712ea0(0x10,param_1,param_2);
    return;
  case 5:
    FUN_00712ea0(0x11,param_1,param_2);
    return;
  case 6:
    break;
  case 7:
    FUN_00712f90(0x17,0,param_1,param_2);
    return;
  case 8:
    FUN_00712f90(0x17,1,param_1,param_2);
    return;
  case 9:
    FUN_00712f90(0x18,1,param_1,param_2);
    return;
  case 10:
    FUN_00712f90(0x19,1,param_1,param_2);
    return;
  case 0xb:
    FUN_00712f90(0x18,0,param_1,param_2);
    return;
  case 0xc:
    FUN_00712f90(0x19,0,param_1,param_2);
    return;
  case 0xd:
    FUN_007122a0();
    FUN_00711fe0();
    *param_1 = *param_2;
    param_1[1] = param_2[1];
    param_1[2] = param_2[2];
    param_1[3] = param_2[3];
    param_1[4] = param_2[4];
    param_1[5] = param_2[5];
    return;
  case 0xe:
    FUN_007122a0();
    FUN_00711fe0();
    *param_1 = *param_2;
    param_1[1] = param_2[1];
    param_1[2] = param_2[2];
    param_1[3] = param_2[3];
    param_1[4] = param_2[4];
    param_1[5] = param_2[5];
    return;
  default:
    return;
  }
  FUN_007126f0();
  if ((*param_2 == 0xb) &&
     (((byte)*(undefined4 *)(*(int *)(*in_ECX + 0xc) + param_2[2] * 4) & 0x3f) == 0x15)) {
    FUN_00712070();
    puVar1 = (uint *)(*(int *)(*in_ECX + 0xc) + param_2[2] * 4);
    *puVar1 = param_1[2] << 0x17 | *puVar1 & 0x7fffff;
    *param_1 = 0xb;
    param_1[2] = param_2[2];
    return;
  }
  FUN_00712630();
  FUN_00712ea0(0x15,param_1,param_2);
  return;
}

