
void FUN_0062d9b0(int *param_1)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  uint uVar3;
  int *unaff_FS_OFFSET;
  int local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090aa90;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&local_10;
  *in_ECX = 0;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  iVar2 = param_1[1];
  iVar1 = *param_1;
  *in_ECX = 0;
  uVar3 = iVar2 - iVar1 >> 2;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  if (uVar3 != 0) {
    if (0x3fffffff < uVar3) {
                    /* WARNING: Subroutine does not return */
      FUN_0087db30("vector<T> too long");
    }
    iVar2 = FUN_007d01e0();
    local_8 = 0;
    *in_ECX = iVar2;
    in_ECX[1] = iVar2;
    in_ECX[2] = iVar2 + uVar3 * 4;
    iVar2 = FUN_00412d40(*param_1,param_1[1],param_1);
    in_ECX[1] = iVar2;
  }
  *unaff_FS_OFFSET = local_10;
  return;
}

