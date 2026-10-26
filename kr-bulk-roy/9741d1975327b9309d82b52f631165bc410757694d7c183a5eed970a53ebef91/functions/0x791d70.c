
undefined4 FUN_00791d70(undefined4 param_1,float *param_2,char param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int *unaff_ESI;
  undefined1 local_24 [4];
  float local_20;
  undefined1 local_1c [4];
  int local_18;
  int local_14;
  int local_10;
  int local_c [2];
  
  puVar1 = (undefined4 *)(**(code **)(*unaff_ESI + 4))(local_24);
  (**(code **)(*unaff_ESI + 4))(local_1c,param_1,unaff_ESI[4]);
  uVar2 = FUN_00796de0(*puVar1);
  local_14 = unaff_ESI[6];
  local_18 = unaff_ESI[5];
  local_c[0] = 0;
  local_10 = 0;
  FUN_00792280(uVar2,local_c,&local_10,&local_20);
  if (param_3 != '\0') {
    *param_2 = (*(float *)(local_10 + 4) - *(float *)(local_c[0] + 4)) * local_20 +
               *(float *)(local_c[0] + 4);
    return 1;
  }
  *param_2 = *(float *)(local_c[0] + 4);
  return 1;
}

