
/* WARNING: Type propagation algorithm not settling */

undefined4 FUN_007921c0(undefined4 param_1,char param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int *unaff_ESI;
  undefined4 *unaff_EDI;
  undefined1 local_28 [4];
  undefined1 local_24 [12];
  undefined1 local_18 [4];
  int local_14;
  int local_10 [3];
  
  puVar1 = (undefined4 *)(**(code **)(*unaff_ESI + 4))(local_28);
  (**(code **)(*unaff_ESI + 4))(local_18,param_1,unaff_ESI[4]);
  uVar2 = FUN_00796de0(*puVar1);
  local_14 = unaff_ESI[6];
  local_10[0] = unaff_ESI[5];
  local_10[2] = 0;
  local_10[1] = 0;
  FUN_00792410(local_10,uVar2,local_10 + 2,local_10 + 1,local_24);
  if (param_2 == '\0') {
    puVar1 = (undefined4 *)(local_10[2] + 4);
  }
  else {
    puVar1 = (undefined4 *)FUN_007924a0(local_10 + 1,local_24);
  }
  if (unaff_EDI != puVar1) {
    unaff_EDI[3] = puVar1[3];
    *unaff_EDI = *puVar1;
    unaff_EDI[1] = puVar1[1];
    unaff_EDI[2] = puVar1[2];
  }
  return 1;
}

