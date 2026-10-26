
void FUN_006fa460(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  if ((*(byte *)(*(int *)(param_2 + 0xc) + 5) & 3) != 0) {
    FUN_006f9f70(param_1,*(int *)(param_2 + 0xc));
  }
  if (*(char *)(param_2 + 6) == '\0') {
    if ((*(byte *)(*(int *)(param_2 + 0x10) + 5) & 3) != 0) {
      FUN_006f9f70(param_1,*(int *)(param_2 + 0x10));
    }
    iVar4 = 0;
    if (*(char *)(param_2 + 7) != '\0') {
      piVar3 = (int *)(param_2 + 0x14);
      do {
        iVar1 = *piVar3;
        if ((*(byte *)(iVar1 + 5) & 3) == 0) goto switchD_006fa513_caseD_4;
        *(byte *)(iVar1 + 5) = *(byte *)(iVar1 + 5) & 0xfc;
        switch(*(undefined1 *)(iVar1 + 4)) {
        default:
          goto switchD_006fa513_caseD_4;
        case 5:
          *(undefined4 *)(iVar1 + 0x18) = *(undefined4 *)(param_1 + 0x24);
          break;
        case 6:
          *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(param_1 + 0x24);
          break;
        case 7:
          iVar2 = *(int *)(iVar1 + 8);
          *(byte *)(iVar1 + 5) = *(byte *)(iVar1 + 5) | 4;
          if ((iVar2 != 0) && ((*(byte *)(iVar2 + 5) & 3) != 0)) {
            FUN_006f9f70(param_1,iVar2);
          }
          if ((*(byte *)(*(int *)(iVar1 + 0xc) + 5) & 3) != 0) {
            FUN_006f9f70(param_1,*(int *)(iVar1 + 0xc));
          }
          goto switchD_006fa513_caseD_4;
        case 8:
          *(undefined4 *)(iVar1 + 0x6c) = *(undefined4 *)(param_1 + 0x24);
          break;
        case 9:
          *(undefined4 *)(iVar1 + 0x44) = *(undefined4 *)(param_1 + 0x24);
          break;
        case 10:
          if ((3 < (*(int **)(iVar1 + 8))[2]) &&
             (iVar2 = **(int **)(iVar1 + 8), (*(byte *)(iVar2 + 5) & 3) != 0)) {
            FUN_006f9f70(param_1,iVar2);
          }
          if (*(int *)(iVar1 + 8) == iVar1 + 0x10) {
            *(byte *)(iVar1 + 5) = *(byte *)(iVar1 + 5) | 4;
          }
          goto switchD_006fa513_caseD_4;
        }
        *(int *)(param_1 + 0x24) = iVar1;
switchD_006fa513_caseD_4:
        iVar4 = iVar4 + 1;
        piVar3 = piVar3 + 1;
      } while (iVar4 < (int)(uint)*(byte *)(param_2 + 7));
    }
  }
  else {
    iVar4 = 0;
    if (*(char *)(param_2 + 7) != '\0') {
      piVar3 = (int *)(param_2 + 0x18);
      do {
        if ((3 < piVar3[2]) && ((*(byte *)(*piVar3 + 5) & 3) != 0)) {
          FUN_006f9f70(param_1,*piVar3);
        }
        iVar4 = iVar4 + 1;
        piVar3 = piVar3 + 4;
      } while (iVar4 < (int)(uint)*(byte *)(param_2 + 7));
      return;
    }
  }
  return;
}

