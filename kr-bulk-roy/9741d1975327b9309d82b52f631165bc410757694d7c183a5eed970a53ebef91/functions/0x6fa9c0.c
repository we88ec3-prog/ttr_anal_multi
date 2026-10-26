
void FUN_006fa9c0(int param_1)

{
  byte *pbVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  do {
    if (param_1 == 0) {
      return;
    }
    iVar5 = *(int *)(param_1 + 0x1c);
    if (((*(byte *)(param_1 + 5) & 0x10) != 0) && (iVar5 != 0)) {
      iVar4 = iVar5 << 4;
      do {
        iVar4 = iVar4 + -0x10;
        iVar2 = *(int *)(*(int *)(param_1 + 0xc) + 8 + iVar4);
        piVar3 = (int *)(*(int *)(param_1 + 0xc) + iVar4);
        iVar5 = iVar5 + -1;
        if (3 < iVar2) {
          if (iVar2 == 4) {
            *(byte *)(*piVar3 + 5) = *(byte *)(*piVar3 + 5) & 0xfc;
          }
          else if (((*(byte *)(*piVar3 + 5) & 3) != 0) ||
                  ((iVar2 == 7 && ((*(byte *)(*piVar3 + 5) & 8) != 0)))) {
            piVar3[2] = 0;
          }
        }
      } while (iVar5 != 0);
    }
    iVar5 = 1 << (*(byte *)(param_1 + 7) & 0x1f);
    if (iVar5 != 0) {
      iVar4 = iVar5 << 5;
      do {
        iVar4 = iVar4 + -0x20;
        piVar3 = (int *)(*(int *)(param_1 + 0x10) + iVar4);
        iVar5 = iVar5 + -1;
        if (piVar3[2] != 0) {
          if (piVar3[6] < 4) {
LAB_006faa59:
            iVar2 = piVar3[2];
            if (3 < iVar2) {
              if (iVar2 == 4) {
                *(byte *)(*piVar3 + 5) = *(byte *)(*piVar3 + 5) & 0xfc;
              }
              else if (((*(byte *)(*piVar3 + 5) & 3) != 0) ||
                      ((iVar2 == 7 && ((*(byte *)(*piVar3 + 5) & 8) != 0)))) goto LAB_006faa7f;
            }
          }
          else {
            if (piVar3[6] == 4) {
              pbVar1 = (byte *)(piVar3[4] + 5);
              *pbVar1 = *pbVar1 & 0xfc;
              goto LAB_006faa59;
            }
            if ((*(byte *)(piVar3[4] + 5) & 3) == 0) goto LAB_006faa59;
LAB_006faa7f:
            piVar3[2] = 0;
            if (3 < piVar3[6]) {
              piVar3[6] = 0xb;
            }
          }
        }
      } while (iVar5 != 0);
    }
    param_1 = *(int *)(param_1 + 0x18);
  } while( true );
}

