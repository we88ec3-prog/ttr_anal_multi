
void FUN_006fd860(uint param_1)

{
  int *piVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  int unaff_EDI;
  
  iVar3 = *(int *)(unaff_EDI + 0x68);
  iVar4 = *(int *)(unaff_EDI + 0x10);
  while ((iVar3 != 0 && (puVar5 = *(undefined4 **)(unaff_EDI + 0x68), param_1 <= (uint)puVar5[2])))
  {
    *(undefined4 *)(unaff_EDI + 0x68) = *puVar5;
    piVar1 = puVar5 + 4;
    if ((~*(byte *)(iVar4 + 0x14) & *(byte *)((int)puVar5 + 5) & 3) == 0) {
      *(int *)(puVar5[5] + 0x10) = *piVar1;
      *(undefined4 *)(*piVar1 + 0x14) = puVar5[5];
      piVar6 = (int *)puVar5[2];
      *piVar1 = *piVar6;
      puVar5[5] = piVar6[1];
      puVar5[6] = piVar6[2];
      puVar5[2] = piVar1;
      iVar3 = *(int *)(unaff_EDI + 0x10);
      *puVar5 = *(undefined4 *)(iVar3 + 0x1c);
      *(undefined4 **)(iVar3 + 0x1c) = puVar5;
      bVar2 = *(byte *)((int)puVar5 + 5);
      if ((bVar2 & 7) == 0) {
        if (*(char *)(iVar3 + 0x15) == '\x01') {
          *(byte *)((int)puVar5 + 5) = bVar2 | 4;
          if ((3 < ((int *)puVar5[2])[2]) &&
             (iVar3 = *(int *)puVar5[2], (*(byte *)(iVar3 + 5) & 3) != 0)) {
            FUN_006fb5a0(iVar3);
          }
        }
        else {
          *(byte *)((int)puVar5 + 5) = *(byte *)(iVar3 + 0x14) & 3 | bVar2 & 0xf8;
        }
      }
    }
    else {
      if ((int *)puVar5[2] != piVar1) {
        *(int *)(puVar5[5] + 0x10) = *piVar1;
        *(undefined4 *)(*piVar1 + 0x14) = puVar5[5];
      }
      FUN_00700880();
    }
    iVar3 = *(int *)(unaff_EDI + 0x68);
  }
  return;
}

