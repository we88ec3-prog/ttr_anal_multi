
/* WARNING: Type propagation algorithm not settling */

undefined4 FUN_00791e20(undefined4 param_1,undefined4 *param_2,char param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int *unaff_ESI;
  undefined1 local_28 [4];
  undefined1 local_24 [8];
  undefined1 local_1c [4];
  int local_18;
  int local_14 [4];
  
  puVar1 = (undefined4 *)(**(code **)(*unaff_ESI + 4))(local_28);
  (**(code **)(*unaff_ESI + 4))(local_1c,param_1,unaff_ESI[4]);
  uVar2 = FUN_00796de0(*puVar1);
  local_18 = unaff_ESI[6];
  local_14[2] = 0;
  local_14[1] = 0;
  local_14[0] = unaff_ESI[5];
  FUN_00792310(local_14,uVar2,local_14 + 2,local_14 + 1,local_24);
  if (param_3 != '\0') {
    puVar1 = (undefined4 *)FUN_007923a0(local_14 + 1,local_24);
    *param_2 = *puVar1;
    param_2[1] = puVar1[1];
    param_2[2] = puVar1[2];
    return 1;
  }
  *param_2 = *(undefined4 *)(local_14[2] + 4);
  param_2[1] = *(undefined4 *)(local_14[2] + 8);
  param_2[2] = *(undefined4 *)(local_14[2] + 0xc);
  return 1;
}

