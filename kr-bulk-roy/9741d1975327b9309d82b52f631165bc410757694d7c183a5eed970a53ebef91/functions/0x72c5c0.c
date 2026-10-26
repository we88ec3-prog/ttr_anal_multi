
void FUN_0072c5c0(int param_1)

{
  int in_EAX;
  byte bVar1;
  int in_ECX;
  int iVar2;
  ushort uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int local_18;
  uint local_14;
  ushort *local_10;
  uint local_c;
  int local_8;
  
  local_14 = 0xffffffff;
  iVar2 = 7;
  local_8 = 4;
  if (*(ushort *)(param_1 + 2) == 0) {
    iVar2 = 0x8a;
    local_8 = 3;
  }
  if (-1 < in_ECX) {
    local_10 = (ushort *)(param_1 + 6);
    local_18 = in_ECX + 1;
    iVar4 = 0;
    local_c = (uint)*(ushort *)(param_1 + 2);
    do {
      uVar5 = (uint)*local_10;
      param_1 = iVar4 + 1;
      if ((iVar2 <= param_1) || (local_c != uVar5)) {
        if (param_1 < local_8) {
          do {
            uVar6 = (uint)*(ushort *)(in_EAX + 0xa7e + local_c * 4);
            iVar2 = *(int *)(in_EAX + 0x16bc);
            if ((int)(0x10 - uVar6) < iVar2) {
              uVar3 = *(ushort *)(in_EAX + 0xa7c + local_c * 4);
              *(ushort *)(in_EAX + 0x16b8) =
                   *(ushort *)(in_EAX + 0x16b8) | uVar3 << ((byte)iVar2 & 0x1f);
              *(undefined1 *)(*(int *)(in_EAX + 8) + *(int *)(in_EAX + 0x14)) =
                   *(undefined1 *)(in_EAX + 0x16b8);
              *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
              *(undefined1 *)(*(int *)(in_EAX + 0x14) + *(int *)(in_EAX + 8)) =
                   *(undefined1 *)(in_EAX + 0x16b9);
              *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
              iVar2 = *(int *)(in_EAX + 0x16bc) + -0x10;
              *(ushort *)(in_EAX + 0x16b8) =
                   uVar3 >> (0x10U - (char)*(int *)(in_EAX + 0x16bc) & 0x1f);
            }
            else {
              *(ushort *)(in_EAX + 0x16b8) =
                   *(ushort *)(in_EAX + 0x16b8) |
                   *(short *)(in_EAX + 0xa7c + local_c * 4) << ((byte)iVar2 & 0x1f);
            }
            param_1 = param_1 + -1;
            *(uint *)(in_EAX + 0x16bc) = iVar2 + uVar6;
          } while (param_1 != 0);
        }
        else if (local_c == 0) {
          if (param_1 < 0xb) {
            uVar6 = (uint)*(ushort *)(in_EAX + 0xac2);
            bVar1 = (byte)*(int *)(in_EAX + 0x16bc);
            if ((int)(0x10 - uVar6) < *(int *)(in_EAX + 0x16bc)) {
              uVar3 = *(ushort *)(in_EAX + 0xac0);
              *(ushort *)(in_EAX + 0x16b8) = *(ushort *)(in_EAX + 0x16b8) | uVar3 << (bVar1 & 0x1f);
              *(undefined1 *)(*(int *)(in_EAX + 8) + *(int *)(in_EAX + 0x14)) =
                   *(undefined1 *)(in_EAX + 0x16b8);
              *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
              *(undefined1 *)(*(int *)(in_EAX + 0x14) + *(int *)(in_EAX + 8)) =
                   *(undefined1 *)(in_EAX + 0x16b9);
              iVar2 = *(int *)(in_EAX + 0x16bc);
              *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
              *(uint *)(in_EAX + 0x16bc) = iVar2 + -0x10 + uVar6;
              *(ushort *)(in_EAX + 0x16b8) = uVar3 >> (0x10U - (char)iVar2 & 0x1f);
            }
            else {
              *(ushort *)(in_EAX + 0x16b8) =
                   *(ushort *)(in_EAX + 0x16b8) | *(short *)(in_EAX + 0xac0) << (bVar1 & 0x1f);
              *(uint *)(in_EAX + 0x16bc) = *(int *)(in_EAX + 0x16bc) + uVar6;
            }
            iVar2 = *(int *)(in_EAX + 0x16bc);
            uVar3 = (ushort)(iVar4 + -2);
            if (iVar2 < 0xe) {
              *(ushort *)(in_EAX + 0x16b8) =
                   *(ushort *)(in_EAX + 0x16b8) | uVar3 << ((byte)iVar2 & 0x1f);
              iVar2 = iVar2 + 3;
LAB_0072cae9:
              *(int *)(in_EAX + 0x16bc) = iVar2;
            }
            else {
              *(ushort *)(in_EAX + 0x16b8) =
                   *(ushort *)(in_EAX + 0x16b8) | uVar3 << ((byte)iVar2 & 0x1f);
              *(undefined1 *)(*(int *)(in_EAX + 8) + *(int *)(in_EAX + 0x14)) =
                   *(undefined1 *)(in_EAX + 0x16b8);
              *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
              *(undefined1 *)(*(int *)(in_EAX + 0x14) + *(int *)(in_EAX + 8)) =
                   *(undefined1 *)(in_EAX + 0x16b9);
              iVar2 = *(int *)(in_EAX + 0x16bc);
              *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
              *(int *)(in_EAX + 0x16bc) = iVar2 + -0xd;
              *(ushort *)(in_EAX + 0x16b8) = uVar3 >> (0x10U - (char)iVar2 & 0x1f);
            }
          }
          else {
            uVar6 = (uint)*(ushort *)(in_EAX + 0xac6);
            bVar1 = (byte)*(int *)(in_EAX + 0x16bc);
            if ((int)(0x10 - uVar6) < *(int *)(in_EAX + 0x16bc)) {
              uVar3 = *(ushort *)(in_EAX + 0xac4);
              *(ushort *)(in_EAX + 0x16b8) = *(ushort *)(in_EAX + 0x16b8) | uVar3 << (bVar1 & 0x1f);
              *(undefined1 *)(*(int *)(in_EAX + 8) + *(int *)(in_EAX + 0x14)) =
                   *(undefined1 *)(in_EAX + 0x16b8);
              *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
              *(undefined1 *)(*(int *)(in_EAX + 0x14) + *(int *)(in_EAX + 8)) =
                   *(undefined1 *)(in_EAX + 0x16b9);
              iVar2 = *(int *)(in_EAX + 0x16bc);
              *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
              *(uint *)(in_EAX + 0x16bc) = iVar2 + -0x10 + uVar6;
              *(ushort *)(in_EAX + 0x16b8) = uVar3 >> (0x10U - (char)iVar2 & 0x1f);
            }
            else {
              *(ushort *)(in_EAX + 0x16b8) =
                   *(ushort *)(in_EAX + 0x16b8) | *(short *)(in_EAX + 0xac4) << (bVar1 & 0x1f);
              *(uint *)(in_EAX + 0x16bc) = *(int *)(in_EAX + 0x16bc) + uVar6;
            }
            iVar2 = *(int *)(in_EAX + 0x16bc);
            uVar3 = (ushort)(iVar4 + -10);
            if (iVar2 < 10) {
              *(ushort *)(in_EAX + 0x16b8) =
                   *(ushort *)(in_EAX + 0x16b8) | uVar3 << ((byte)iVar2 & 0x1f);
              iVar2 = iVar2 + 7;
              goto LAB_0072cae9;
            }
            *(ushort *)(in_EAX + 0x16b8) =
                 *(ushort *)(in_EAX + 0x16b8) | uVar3 << ((byte)iVar2 & 0x1f);
            *(undefined1 *)(*(int *)(in_EAX + 8) + *(int *)(in_EAX + 0x14)) =
                 *(undefined1 *)(in_EAX + 0x16b8);
            *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
            *(undefined1 *)(*(int *)(in_EAX + 0x14) + *(int *)(in_EAX + 8)) =
                 *(undefined1 *)(in_EAX + 0x16b9);
            iVar2 = *(int *)(in_EAX + 0x16bc);
            *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
            *(int *)(in_EAX + 0x16bc) = iVar2 + -9;
            *(ushort *)(in_EAX + 0x16b8) = uVar3 >> (0x10U - (char)iVar2 & 0x1f);
          }
        }
        else {
          if (local_c != local_14) {
            uVar6 = (uint)*(ushort *)(in_EAX + 0xa7e + local_c * 4);
            bVar1 = (byte)*(int *)(in_EAX + 0x16bc);
            param_1 = iVar4;
            if ((int)(0x10 - uVar6) < *(int *)(in_EAX + 0x16bc)) {
              uVar3 = *(ushort *)(in_EAX + 0xa7c + local_c * 4);
              *(ushort *)(in_EAX + 0x16b8) = *(ushort *)(in_EAX + 0x16b8) | uVar3 << (bVar1 & 0x1f);
              *(undefined1 *)(*(int *)(in_EAX + 8) + *(int *)(in_EAX + 0x14)) =
                   *(undefined1 *)(in_EAX + 0x16b8);
              *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
              *(undefined1 *)(*(int *)(in_EAX + 0x14) + *(int *)(in_EAX + 8)) =
                   *(undefined1 *)(in_EAX + 0x16b9);
              iVar2 = *(int *)(in_EAX + 0x16bc);
              *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
              *(uint *)(in_EAX + 0x16bc) = iVar2 + -0x10 + uVar6;
              *(ushort *)(in_EAX + 0x16b8) = uVar3 >> (0x10U - (char)iVar2 & 0x1f);
            }
            else {
              *(ushort *)(in_EAX + 0x16b8) =
                   *(ushort *)(in_EAX + 0x16b8) |
                   *(short *)(in_EAX + 0xa7c + local_c * 4) << (bVar1 & 0x1f);
              *(uint *)(in_EAX + 0x16bc) = *(int *)(in_EAX + 0x16bc) + uVar6;
            }
          }
          uVar6 = (uint)*(ushort *)(in_EAX + 0xabe);
          iVar2 = *(int *)(in_EAX + 0x16bc);
          if ((int)(0x10 - uVar6) < iVar2) {
            uVar3 = *(ushort *)(in_EAX + 0xabc);
            *(ushort *)(in_EAX + 0x16b8) =
                 *(ushort *)(in_EAX + 0x16b8) | uVar3 << ((byte)iVar2 & 0x1f);
            *(undefined1 *)(*(int *)(in_EAX + 8) + *(int *)(in_EAX + 0x14)) =
                 *(undefined1 *)(in_EAX + 0x16b8);
            *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
            *(undefined1 *)(*(int *)(in_EAX + 0x14) + *(int *)(in_EAX + 8)) =
                 *(undefined1 *)(in_EAX + 0x16b9);
            iVar2 = *(int *)(in_EAX + 0x16bc);
            *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
            *(uint *)(in_EAX + 0x16bc) = iVar2 + -0x10 + uVar6;
            *(ushort *)(in_EAX + 0x16b8) = uVar3 >> (0x10U - (char)iVar2 & 0x1f);
          }
          else {
            *(ushort *)(in_EAX + 0x16b8) =
                 *(ushort *)(in_EAX + 0x16b8) | *(short *)(in_EAX + 0xabc) << ((byte)iVar2 & 0x1f);
            *(uint *)(in_EAX + 0x16bc) = iVar2 + uVar6;
          }
          iVar2 = *(int *)(in_EAX + 0x16bc);
          uVar3 = (ushort)(param_1 + -3);
          if (iVar2 < 0xf) {
            *(ushort *)(in_EAX + 0x16b8) =
                 *(ushort *)(in_EAX + 0x16b8) | uVar3 << ((byte)iVar2 & 0x1f);
            iVar2 = iVar2 + 2;
            goto LAB_0072cae9;
          }
          *(ushort *)(in_EAX + 0x16b8) =
               *(ushort *)(in_EAX + 0x16b8) | uVar3 << ((byte)iVar2 & 0x1f);
          *(undefined1 *)(*(int *)(in_EAX + 8) + *(int *)(in_EAX + 0x14)) =
               *(undefined1 *)(in_EAX + 0x16b8);
          *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
          *(undefined1 *)(*(int *)(in_EAX + 0x14) + *(int *)(in_EAX + 8)) =
               *(undefined1 *)(in_EAX + 0x16b9);
          iVar2 = *(int *)(in_EAX + 0x16bc);
          *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
          *(int *)(in_EAX + 0x16bc) = iVar2 + -0xe;
          *(ushort *)(in_EAX + 0x16b8) = uVar3 >> (0x10U - (char)iVar2 & 0x1f);
        }
        param_1 = 0;
        local_14 = local_c;
        if (uVar5 == 0) {
          iVar2 = 0x8a;
          local_8 = 3;
        }
        else if (local_c == uVar5) {
          iVar2 = 6;
          local_8 = 3;
        }
        else {
          iVar2 = 7;
          local_8 = 4;
        }
      }
      local_10 = local_10 + 2;
      local_18 = local_18 + -1;
      iVar4 = param_1;
      local_c = uVar5;
    } while (local_18 != 0);
  }
  return;
}

