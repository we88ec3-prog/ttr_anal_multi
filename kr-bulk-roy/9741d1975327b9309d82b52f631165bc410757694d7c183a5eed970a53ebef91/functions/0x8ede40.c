
void FUN_008ede40(int param_1)

{
  int *piVar1;
  byte *pbVar2;
  int in_EAX;
  ushort in_CX;
  char unaff_BL;
  uint uVar3;
  int unaff_EDI;
  
  uVar3 = (uint)in_CX;
  if ((*(short *)(in_EAX + 0x12a) != 0) &&
     (piVar1 = (int *)(*(int *)(in_EAX + 0x7c) + uVar3 * 8), *piVar1 = *piVar1 + unaff_EDI,
     unaff_BL != '\0')) {
    pbVar2 = (byte *)(uVar3 + *(int *)(in_EAX + 0x84));
    *pbVar2 = *pbVar2 | 8;
  }
  if ((*(short *)(in_EAX + 300) != 0) &&
     (piVar1 = (int *)(*(int *)(in_EAX + 0x7c) + 4 + uVar3 * 8), *piVar1 = *piVar1 + param_1,
     unaff_BL != '\0')) {
    pbVar2 = (byte *)(*(int *)(in_EAX + 0x84) + uVar3);
    *pbVar2 = *pbVar2 | 0x10;
  }
  return;
}

