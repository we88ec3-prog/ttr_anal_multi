
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00791a80(undefined4 param_1,undefined4 *param_2,char param_3)

{
  int *in_EAX;
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined1 local_24 [4];
  undefined1 local_20 [4];
  undefined1 local_1c [4];
  int local_18;
  int local_14 [4];
  
  if ((char)in_EAX[5] == '\0') {
    if (DAT_00fe3210 == (undefined *)0x0) {
      if ((_DAT_00fe3538 & 1) == 0) {
        _DAT_00fe3538 = _DAT_00fe3538 | 1;
      }
      DAT_00fe3210 = &DAT_00fe3527;
    }
    FUN_00793440();
  }
  puVar1 = (undefined4 *)(**(code **)(*in_EAX + 4))(local_24);
  (**(code **)(*in_EAX + 4))(local_1c,param_1,in_EAX[4]);
  uVar2 = FUN_00796de0(*puVar1);
  local_18 = in_EAX[7];
  local_14[0] = in_EAX[6];
  local_14[2] = 0;
  local_14[1] = 0;
  FUN_007920a0(local_14,uVar2,local_14 + 2,local_14 + 1,local_20);
  if (param_3 != '\0') {
    if (DAT_00fe3210 == (undefined *)0x0) {
      if ((_DAT_00fe3538 & 1) == 0) {
        _DAT_00fe3538 = _DAT_00fe3538 | 1;
      }
      DAT_00fe3210 = &DAT_00fe3527;
    }
    FUN_007936c0(local_14 + 1);
    return 1;
  }
  *param_2 = *(undefined4 *)(local_14[2] + 4);
  param_2[1] = *(undefined4 *)(local_14[2] + 8);
  param_2[2] = *(undefined4 *)(local_14[2] + 0xc);
  return 1;
}

