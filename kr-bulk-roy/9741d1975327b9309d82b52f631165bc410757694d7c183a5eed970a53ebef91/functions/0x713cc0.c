
void FUN_00713cc0(char *param_1)

{
  char cVar1;
  int *piVar2;
  FILE *pFVar3;
  int iVar4;
  undefined4 uVar5;
  char *in_ECX;
  int *piVar6;
  char local_28 [16];
  char local_18 [16];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  piVar2 = (int *)FUN_00891268(0x10);
  piVar6 = (int *)0x0;
  if (piVar2 != (int *)0x0) {
    piVar2[1] = 0;
    piVar2[2] = 0;
    piVar2[3] = 0;
    *piVar2 = (int)StdFile::vftable;
    piVar6 = piVar2;
  }
  pFVar3 = _fopen(in_ECX,param_1);
  piVar6[1] = (int)pFVar3;
  if (pFVar3 == (FILE *)0x0) {
    (**(code **)*piVar6)(1);
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  (*(code *)((undefined4 *)*piVar6)[0xd])(0,2);
  iVar4 = (**(code **)(*piVar6 + 0x30))();
  piVar6[3] = iVar4;
  (**(code **)(*piVar6 + 0x34))(0,0);
  if (DAT_00fba81c != (int *)0x0) {
    local_18[1] = '\0';
    local_18[2] = '\0';
    local_18[3] = '\0';
    local_18[4] = '\0';
    local_18[5] = '\0';
    local_18[6] = '\0';
    local_18[7] = '\0';
    local_18[8] = '\0';
    local_18[9] = '\0';
    local_18[10] = '\0';
    local_18[0xb] = '\0';
    local_18[0xc] = '\0';
    local_18[0xd] = '\0';
    local_18[0xe] = '\0';
    local_18[0xf] = 0;
    local_18[0] = '\0';
    cVar1 = (**(code **)*DAT_00fba81c)();
    if (cVar1 != '\0') {
      iVar4 = *DAT_00fba81c;
      uVar5 = (**(code **)(*piVar6 + 0x38))(piVar6[3],local_28);
      (**(code **)(iVar4 + 8))(uVar5);
      iVar4 = 0;
      do {
        if (local_18[iVar4] != local_28[iVar4]) {
          (**(code **)*piVar6)(1);
          __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
          return;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < 0x10);
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

