
int FUN_00773200(uint param_1,int *param_2)

{
  int *piVar1;
  uint uVar2;
  int in_ECX;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  if (((uint)param_2 & 1) == 0) {
    if (((uint)param_2 & 2) == 0) {
      return 0;
    }
    iVar6 = in_ECX + 0x6c;
  }
  else {
    iVar6 = in_ECX + 0x5c;
  }
  if ((iVar6 != 0) && (*(int *)(iVar6 + 8) != 0)) {
    if (*(char *)(in_ECX + 0x7c) != '\0') {
      piVar1 = *(int **)(iVar6 + 4);
      param_2 = (int *)*piVar1;
      iVar6 = param_2[4];
      iVar5 = 0;
      do {
        if (param_2 == piVar1) {
LAB_00773265:
          if (iVar6 == 0) {
            if (iVar5 == 0) {
              return 0;
            }
          }
          else if ((iVar5 == 0) ||
                  (uVar2 = param_1 - *(int *)(iVar5 + 0x10), uVar3 = (int)uVar2 >> 0x1f,
                  param_1 = param_1 - *(int *)(iVar6 + 0x10), uVar4 = (int)param_1 >> 0x1f,
                  (int)((param_1 ^ uVar4) - uVar4) <= (int)((uVar2 ^ uVar3) - uVar3))) {
            return iVar6;
          }
          return iVar5;
        }
        if (param_1 < (uint)param_2[3]) {
          iVar5 = param_2[4];
          goto LAB_00773265;
        }
        iVar6 = param_2[4];
        FUN_0049e6a0();
      } while( true );
    }
    FUN_008438c0(&param_1);
    if (param_2 != (int *)*(uint *)(iVar6 + 4)) {
      return *(int *)((int)param_2 + 0x10);
    }
  }
  return 0;
}

