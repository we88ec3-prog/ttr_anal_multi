
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_007919a0(undefined4 param_1,char param_2)

{
  undefined4 *in_EAX;
  undefined4 *puVar1;
  undefined4 uVar2;
  int *in_ECX;
  undefined1 local_20 [4];
  undefined1 local_1c [4];
  undefined1 local_18 [4];
  int local_14;
  int local_10 [3];
  
  puVar1 = (undefined4 *)(**(code **)(*in_ECX + 4))(local_20);
  (**(code **)(*in_ECX + 4))(local_18,param_1,in_ECX[4]);
  uVar2 = FUN_00796de0(*puVar1);
  local_14 = in_ECX[7];
  local_10[0] = in_ECX[6];
  local_10[2] = 0;
  local_10[1] = 0;
  FUN_00792010(local_10,uVar2,local_10 + 2,local_10 + 1,local_1c);
  if (param_2 != '\0') {
    if (DAT_00fe3218 == (undefined *)0x0) {
      if ((_DAT_00fe3534 & 1) == 0) {
        _DAT_00fe3534 = _DAT_00fe3534 | 1;
      }
      DAT_00fe3218 = &DAT_00fe3526;
    }
    FUN_007961e0();
    return 1;
  }
  if (in_EAX != (undefined4 *)(local_10[2] + 4)) {
    in_EAX[3] = *(undefined4 *)(local_10[2] + 0x10);
    *in_EAX = *(undefined4 *)(local_10[2] + 4);
    in_EAX[1] = *(undefined4 *)(local_10[2] + 8);
    in_EAX[2] = *(undefined4 *)(local_10[2] + 0xc);
  }
  return 1;
}

