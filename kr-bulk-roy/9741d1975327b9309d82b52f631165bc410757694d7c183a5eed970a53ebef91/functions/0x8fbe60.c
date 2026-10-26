
uint FUN_008fbe60(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  undefined1 *in_EAX;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  
  uVar1 = in_EAX[2];
  uVar9 = (uint)(byte)in_EAX[3];
  uVar2 = in_EAX[1];
  if (uVar9 == 0) {
    return (uint)in_EAX & 0xffffff00;
  }
  iVar6 = FUN_008b7dc0(*in_EAX,0x10000,uVar9);
  iVar7 = FUN_008b7dc0(uVar2,0x10000,uVar9);
  iVar8 = FUN_008b7dc0(uVar1,0x10000,uVar9);
  lVar3 = (longlong)iVar6 * (longlong)iVar6 +
          (ulonglong)((int)((longlong)iVar6 * (longlong)iVar6 >> 0x3f) + 0x8000);
  iVar6 = ((uint)lVar3 >> 0x10) + (int)((ulonglong)lVar3 >> 0x20) * 0x10000;
  lVar3 = (longlong)iVar7 * (longlong)iVar7 +
          (ulonglong)((int)((longlong)iVar7 * (longlong)iVar7 >> 0x3f) + 0x8000);
  iVar7 = ((uint)lVar3 >> 0x10) + (int)((ulonglong)lVar3 >> 0x20) * 0x10000;
  lVar3 = (longlong)iVar8 * (longlong)iVar8 +
          (ulonglong)((int)((longlong)iVar8 * (longlong)iVar8 >> 0x3f) + 0x8000);
  iVar8 = ((uint)lVar3 >> 0x10) + (int)((ulonglong)lVar3 >> 0x20) * 0x10000;
  lVar3 = (longlong)iVar6 * 0x127b + (ulonglong)((iVar6 >> 0x1f) + 0x8000);
  lVar4 = (longlong)iVar7 * 0xb717 + (ulonglong)((iVar7 >> 0x1f) + 0x8000);
  lVar5 = (longlong)iVar8 * 0x366d + (ulonglong)((iVar8 >> 0x1f) + 0x8000);
  lVar3 = (longlong)
          (int)(((0xffff - (((uint)lVar5 >> 0x10) + (int)((ulonglong)lVar5 >> 0x20) * 0x10000)) -
                (((uint)lVar4 >> 0x10) + (int)((ulonglong)lVar4 >> 0x20) * 0x10000)) -
               (((uint)lVar3 >> 0x10) + (int)((ulonglong)lVar3 >> 0x20) * 0x10000)) *
          (longlong)(int)(uVar9 << 8);
  lVar3 = lVar3 + (ulonglong)((int)(lVar3 >> 0x3f) + 0x8000);
  return (int)(((uint)lVar3 >> 0x10) + (int)((ulonglong)lVar3 >> 0x20) * 0x10000) >> 8;
}

