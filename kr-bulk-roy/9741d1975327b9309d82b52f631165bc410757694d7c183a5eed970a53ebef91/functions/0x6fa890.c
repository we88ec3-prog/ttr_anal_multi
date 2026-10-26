
int FUN_006fa890(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = 0;
  iVar3 = *(int *)(param_1 + 0x24);
  while (iVar3 != 0) {
    iVar3 = *(int *)(param_1 + 0x24);
    *(byte *)(iVar3 + 5) = *(byte *)(iVar3 + 5) | 4;
    switch(*(undefined1 *)(iVar3 + 4)) {
    case 5:
      *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(iVar3 + 0x18);
      iVar2 = FUN_006fa1e0(param_1);
      if (iVar2 != 0) {
        *(byte *)(iVar3 + 5) = *(byte *)(iVar3 + 5) & 0xfb;
      }
      iVar3 = (*(int *)(iVar3 + 0x1c) + 2 + (1 << (*(byte *)(iVar3 + 7) & 0x1f)) * 2) * 0x10;
      break;
    case 6:
      *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(iVar3 + 8);
      FUN_006fa460(param_1,iVar3);
      if (*(char *)(iVar3 + 6) == '\0') {
        iVar3 = (uint)*(byte *)(iVar3 + 7) * 4 + 0x14;
      }
      else {
        iVar3 = (uint)*(byte *)(iVar3 + 7) * 0x10 + 0x18;
      }
      break;
    default:
      iVar3 = 0;
      break;
    case 8:
      *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(iVar3 + 0x6c);
      *(undefined4 *)(iVar3 + 0x6c) = *(undefined4 *)(param_1 + 0x28);
      *(int *)(param_1 + 0x28) = iVar3;
      *(byte *)(iVar3 + 5) = *(byte *)(iVar3 + 5) & 0xfb;
      FUN_006fa5e0(param_1);
      iVar3 = *(int *)(iVar3 + 0x2c) * 0x10 + (*(int *)(iVar3 + 0x30) * 3 + 0xf) * 8;
      break;
    case 9:
      *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(iVar3 + 0x44);
      FUN_006fa390(param_1);
      iVar3 = (*(int *)(iVar3 + 0x38) * 3 + *(int *)(iVar3 + 0x28) * 4 + *(int *)(iVar3 + 0x34) +
               *(int *)(iVar3 + 0x30) + *(int *)(iVar3 + 0x2c) + *(int *)(iVar3 + 0x24)) * 4 + 0x4c;
    }
    iVar1 = iVar1 + iVar3;
    iVar3 = *(int *)(param_1 + 0x24);
  }
  return iVar1;
}

