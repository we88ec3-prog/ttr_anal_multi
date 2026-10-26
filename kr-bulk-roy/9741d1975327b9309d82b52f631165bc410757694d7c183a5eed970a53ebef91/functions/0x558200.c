
void FUN_00558200(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int *unaff_EDI;
  undefined4 *local_8;
  
  if (0 < unaff_EDI[9]) {
    FUN_00804260(&param_1);
    return;
  }
  unaff_EDI[9] = 0x12;
  local_8 = (undefined4 *)FUN_00891268(0x2c);
  if (local_8 == (undefined4 *)0x0) {
    local_8 = (undefined4 *)0x0;
  }
  else {
    *local_8 = 0;
    local_8[3] = 0;
    local_8[4] = 0;
    local_8[5] = 0;
    local_8[6] = 0xc0c00000;
    local_8[7] = 0;
    local_8[8] = 0x3e99999a;
    local_8[9] = 0x23;
    local_8[10] = 0;
  }
  FUN_00557e10(local_8,param_1);
  iVar1 = *unaff_EDI;
  iVar2 = FUN_0074d700(iVar1,*(undefined4 *)(iVar1 + 4),&local_8);
  if (unaff_EDI[1] == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  unaff_EDI[1] = unaff_EDI[1] + 1;
  *(int *)(iVar1 + 4) = iVar2;
  **(int **)(iVar2 + 4) = iVar2;
  return;
}

