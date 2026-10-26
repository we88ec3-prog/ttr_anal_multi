
void FUN_004c89a0(void)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  uint uVar4;
  int in_ECX;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 in_XMM0_Da;
  
  if (*(int *)(in_ECX + 0x3a8) == 0) {
    bVar1 = *(byte *)(in_ECX + 0x3a4);
    uVar4 = (uint)*(byte *)(in_ECX + 0xb0) - (uint)bVar1;
    if (uVar4 != 0) {
      iVar5 = (uint)bVar1 - (uint)*(byte *)(in_ECX + 0xb0);
      uVar7 = uVar4;
      if ((int)uVar4 < 0) {
        uVar7 = uVar4 + 0x100;
      }
      if (iVar5 < 0) {
        iVar5 = iVar5 + 0x100;
      }
      uVar6 = (int)uVar4 >> 0x1f;
      if (iVar5 < (int)uVar7) {
        iVar5 = (uVar4 ^ uVar6) - uVar6;
        *(undefined4 *)(in_ECX + 0x3ac) = 0xffffffff;
        if (0x10 < iVar5) {
          iVar5 = 0x10;
        }
        bVar2 = (byte)(iVar5 >> 0x1f);
        cVar3 = -(((byte)iVar5 ^ bVar2) - bVar2);
      }
      else if ((int)uVar7 < iVar5) {
        iVar5 = (uVar4 ^ uVar6) - uVar6;
        *(undefined4 *)(in_ECX + 0x3ac) = 1;
        if (0x10 < iVar5) {
          iVar5 = 0x10;
        }
        bVar2 = (byte)(iVar5 >> 0x1f);
        cVar3 = ((byte)iVar5 ^ bVar2) - bVar2;
      }
      else {
        iVar5 = (uVar4 ^ uVar6) - uVar6;
        if (0x30 < iVar5) {
          iVar5 = 0x30;
        }
        bVar2 = (byte)(iVar5 >> 0x1f);
        cVar3 = (((byte)iVar5 ^ bVar2) - bVar2) * (char)*(undefined4 *)(in_ECX + 0x3ac);
      }
      *(byte *)(in_ECX + 0x3a4) = cVar3 + bVar1;
      if ((*(int *)(in_ECX + 0x370) != 0) && (*(int *)(in_ECX + 0x15c) != 0)) {
        iVar5 = *(int *)(*(int *)(in_ECX + 0x15c) + 4);
        FUN_00444a90(cVar3 + bVar1);
        (**(code **)(iVar5 + 0xc))(in_XMM0_Da);
      }
    }
  }
  return;
}

