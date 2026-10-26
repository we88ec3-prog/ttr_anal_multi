
void FUN_0072d300(int param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  int in_EAX;
  byte bVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  ushort uVar7;
  uint uVar8;
  uint uVar9;
  
  uVar6 = 0;
  if (*(int *)(in_EAX + 0x16a0) != 0) {
    do {
      uVar4 = (uint)*(ushort *)(*(int *)(in_EAX + 0x16a4) + uVar6 * 2);
      bVar1 = *(byte *)(uVar6 + *(int *)(in_EAX + 0x1698));
      uVar8 = (uint)bVar1;
      uVar6 = uVar6 + 1;
      iVar5 = *(int *)(in_EAX + 0x16bc);
      bVar3 = (byte)iVar5;
      if (uVar4 == 0) {
        uVar4 = (uint)*(ushort *)(param_1 + 2 + uVar8 * 4);
        if ((int)(0x10 - uVar4) < iVar5) {
          uVar7 = *(ushort *)(param_1 + uVar8 * 4);
          *(ushort *)(in_EAX + 0x16b8) = *(ushort *)(in_EAX + 0x16b8) | uVar7 << (bVar3 & 0x1f);
          *(undefined1 *)(*(int *)(in_EAX + 8) + *(int *)(in_EAX + 0x14)) =
               *(undefined1 *)(in_EAX + 0x16b8);
          *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
          *(undefined1 *)(*(int *)(in_EAX + 0x14) + *(int *)(in_EAX + 8)) =
               *(undefined1 *)(in_EAX + 0x16b9);
          iVar5 = *(int *)(in_EAX + 0x16bc);
          *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
          *(uint *)(in_EAX + 0x16bc) = iVar5 + -0x10 + uVar4;
          *(ushort *)(in_EAX + 0x16b8) = uVar7 >> (0x10U - (char)iVar5 & 0x1f);
        }
        else {
          *(ushort *)(in_EAX + 0x16b8) =
               *(ushort *)(in_EAX + 0x16b8) | *(short *)(param_1 + uVar8 * 4) << (bVar3 & 0x1f);
          iVar5 = iVar5 + uVar4;
LAB_0072d63e:
          *(int *)(in_EAX + 0x16bc) = iVar5;
        }
      }
      else {
        uVar9 = (uint)(byte)(&DAT_00c089a0)[uVar8];
        uVar8 = (uint)*(ushort *)(param_1 + 0x406 + uVar9 * 4);
        if ((int)(0x10 - uVar8) < iVar5) {
          uVar7 = *(ushort *)(param_1 + 0x404 + uVar9 * 4);
          *(ushort *)(in_EAX + 0x16b8) = *(ushort *)(in_EAX + 0x16b8) | uVar7 << (bVar3 & 0x1f);
          *(undefined1 *)(*(int *)(in_EAX + 8) + *(int *)(in_EAX + 0x14)) =
               *(undefined1 *)(in_EAX + 0x16b8);
          *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
          *(undefined1 *)(*(int *)(in_EAX + 0x14) + *(int *)(in_EAX + 8)) =
               *(undefined1 *)(in_EAX + 0x16b9);
          iVar5 = *(int *)(in_EAX + 0x16bc);
          *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
          *(uint *)(in_EAX + 0x16bc) = iVar5 + -0x10 + uVar8;
          *(ushort *)(in_EAX + 0x16b8) = uVar7 >> (0x10U - (char)iVar5 & 0x1f);
        }
        else {
          *(ushort *)(in_EAX + 0x16b8) =
               *(ushort *)(in_EAX + 0x16b8) |
               *(short *)(param_1 + 0x404 + uVar9 * 4) << (bVar3 & 0x1f);
          *(uint *)(in_EAX + 0x16bc) = iVar5 + uVar8;
        }
        iVar5 = *(int *)(&DAT_00c08158 + uVar9 * 4);
        if (iVar5 != 0) {
          uVar7 = (ushort)bVar1 - (short)*(undefined4 *)(&DAT_00c08aa0 + uVar9 * 4);
          iVar2 = *(int *)(in_EAX + 0x16bc);
          if (0x10 - iVar5 < iVar2) {
            *(ushort *)(in_EAX + 0x16b8) =
                 *(ushort *)(in_EAX + 0x16b8) | uVar7 << ((byte)iVar2 & 0x1f);
            *(undefined1 *)(*(int *)(in_EAX + 8) + *(int *)(in_EAX + 0x14)) =
                 *(undefined1 *)(in_EAX + 0x16b8);
            *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
            *(undefined1 *)(*(int *)(in_EAX + 0x14) + *(int *)(in_EAX + 8)) =
                 *(undefined1 *)(in_EAX + 0x16b9);
            *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
            iVar2 = *(int *)(in_EAX + 0x16bc) + -0x10;
            *(ushort *)(in_EAX + 0x16b8) = uVar7 >> (0x10U - (char)*(int *)(in_EAX + 0x16bc) & 0x1f)
            ;
          }
          else {
            *(ushort *)(in_EAX + 0x16b8) =
                 *(ushort *)(in_EAX + 0x16b8) | uVar7 << ((byte)iVar2 & 0x1f);
          }
          *(int *)(in_EAX + 0x16bc) = iVar2 + iVar5;
        }
        uVar8 = uVar4 - 1;
        if (uVar8 < 0x100) {
          bVar1 = (&DAT_00c0879f)[uVar4];
        }
        else {
          bVar1 = (&DAT_00c088a0)[uVar8 >> 7];
        }
        uVar4 = (uint)bVar1;
        uVar9 = (uint)*(ushort *)(param_2 + 2 + uVar4 * 4);
        iVar5 = *(int *)(in_EAX + 0x16bc);
        if ((int)(0x10 - uVar9) < iVar5) {
          uVar7 = *(ushort *)(param_2 + uVar4 * 4);
          *(ushort *)(in_EAX + 0x16b8) =
               *(ushort *)(in_EAX + 0x16b8) | uVar7 << ((byte)iVar5 & 0x1f);
          *(undefined1 *)(*(int *)(in_EAX + 8) + *(int *)(in_EAX + 0x14)) =
               *(undefined1 *)(in_EAX + 0x16b8);
          *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
          *(undefined1 *)(*(int *)(in_EAX + 0x14) + *(int *)(in_EAX + 8)) =
               *(undefined1 *)(in_EAX + 0x16b9);
          iVar5 = *(int *)(in_EAX + 0x16bc);
          *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
          *(uint *)(in_EAX + 0x16bc) = iVar5 + -0x10 + uVar9;
          *(ushort *)(in_EAX + 0x16b8) = uVar7 >> (0x10U - (char)iVar5 & 0x1f);
        }
        else {
          *(ushort *)(in_EAX + 0x16b8) =
               *(ushort *)(in_EAX + 0x16b8) |
               *(short *)(param_2 + uVar4 * 4) << ((byte)iVar5 & 0x1f);
          *(uint *)(in_EAX + 0x16bc) = iVar5 + uVar9;
        }
        iVar2 = *(int *)(&DAT_00c081e0 + uVar4 * 4);
        if (iVar2 != 0) {
          uVar7 = (short)uVar8 - (short)*(undefined4 *)(&DAT_00c08b18 + uVar4 * 4);
          iVar5 = *(int *)(in_EAX + 0x16bc);
          if (iVar5 <= 0x10 - iVar2) {
            *(ushort *)(in_EAX + 0x16b8) =
                 *(ushort *)(in_EAX + 0x16b8) | uVar7 << ((byte)iVar5 & 0x1f);
            iVar5 = iVar5 + iVar2;
            goto LAB_0072d63e;
          }
          *(ushort *)(in_EAX + 0x16b8) =
               *(ushort *)(in_EAX + 0x16b8) | uVar7 << ((byte)iVar5 & 0x1f);
          *(undefined1 *)(*(int *)(in_EAX + 8) + *(int *)(in_EAX + 0x14)) =
               *(undefined1 *)(in_EAX + 0x16b8);
          *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
          *(undefined1 *)(*(int *)(in_EAX + 0x14) + *(int *)(in_EAX + 8)) =
               *(undefined1 *)(in_EAX + 0x16b9);
          *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
          *(ushort *)(in_EAX + 0x16b8) = uVar7 >> (0x10U - (char)*(int *)(in_EAX + 0x16bc) & 0x1f);
          *(int *)(in_EAX + 0x16bc) = *(int *)(in_EAX + 0x16bc) + -0x10 + iVar2;
        }
      }
    } while (uVar6 < *(uint *)(in_EAX + 0x16a0));
  }
  uVar6 = (uint)*(ushort *)(param_1 + 0x402);
  iVar5 = *(int *)(in_EAX + 0x16bc);
  if (iVar5 <= (int)(0x10 - uVar6)) {
    *(ushort *)(in_EAX + 0x16b8) =
         *(ushort *)(in_EAX + 0x16b8) | *(short *)(param_1 + 0x400) << ((byte)iVar5 & 0x1f);
    *(uint *)(in_EAX + 0x16bc) = iVar5 + uVar6;
    *(uint *)(in_EAX + 0x16b4) = (uint)*(ushort *)(param_1 + 0x402);
    return;
  }
  uVar7 = *(ushort *)(param_1 + 0x400);
  *(ushort *)(in_EAX + 0x16b8) = *(ushort *)(in_EAX + 0x16b8) | uVar7 << ((byte)iVar5 & 0x1f);
  *(undefined1 *)(*(int *)(in_EAX + 8) + *(int *)(in_EAX + 0x14)) = *(undefined1 *)(in_EAX + 0x16b8)
  ;
  *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
  *(undefined1 *)(*(int *)(in_EAX + 0x14) + *(int *)(in_EAX + 8)) = *(undefined1 *)(in_EAX + 0x16b9)
  ;
  iVar5 = *(int *)(in_EAX + 0x16bc);
  *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
  *(uint *)(in_EAX + 0x16bc) = iVar5 + -0x10 + uVar6;
  *(ushort *)(in_EAX + 0x16b8) = uVar7 >> (0x10U - (char)iVar5 & 0x1f);
  *(uint *)(in_EAX + 0x16b4) = (uint)*(ushort *)(param_1 + 0x402);
  return;
}

