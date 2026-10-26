
void FUN_005809d0(uint *param_1)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  undefined4 *puVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00921088;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar2 = (undefined4 *)param_1[1];
  if ((in_ECX < puVar2) && (puVar1 = (undefined4 *)*param_1, puVar1 <= in_ECX)) {
    if (puVar2 == (undefined4 *)param_1[2]) {
      FUN_00580ae0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    }
    puVar2 = (undefined4 *)param_1[1];
    in_ECX = (undefined4 *)((((int)in_ECX - (int)puVar1) / 0x34) * 0x34 + *param_1);
    local_8 = 0;
    if (puVar2 == (undefined4 *)0x0) goto LAB_00580ac5;
    *puVar2 = *in_ECX;
    puVar2[1] = in_ECX[1];
    puVar2[6] = 0;
    puVar2[7] = 0xf;
    *(undefined1 *)(puVar2 + 2) = 0;
    FUN_00403040(in_ECX + 2,0,0xffffffff);
    local_8 = CONCAT31(local_8._1_3_,1);
  }
  else {
    if (puVar2 == (undefined4 *)param_1[2]) {
      FUN_00580ae0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    }
    puVar2 = (undefined4 *)param_1[1];
    local_8 = 2;
    if (puVar2 == (undefined4 *)0x0) goto LAB_00580ac5;
    *puVar2 = *in_ECX;
    puVar2[1] = in_ECX[1];
    puVar2[6] = 0;
    puVar2[7] = 0xf;
    *(undefined1 *)(puVar2 + 2) = 0;
    FUN_00403040(in_ECX + 2,0,0xffffffff);
    local_8 = CONCAT31(local_8._1_3_,3);
  }
  FUN_00580c60(puVar2 + 9,in_ECX + 9);
LAB_00580ac5:
  param_1[1] = param_1[1] + 0x34;
  ExceptionList = local_10;
  return;
}

