
/* WARNING: Removing unreachable block (ram,0x007c34b6) */
/* WARNING: Removing unreachable block (ram,0x007c34ca) */
/* WARNING: Removing unreachable block (ram,0x007c3ad3) */
/* WARNING: Removing unreachable block (ram,0x007c3ae0) */
/* WARNING: Removing unreachable block (ram,0x007c3ae8) */
/* WARNING: Removing unreachable block (ram,0x007c3aee) */
/* WARNING: Removing unreachable block (ram,0x007c3afc) */
/* WARNING: Removing unreachable block (ram,0x007c3b2c) */
/* WARNING: Removing unreachable block (ram,0x007c3b18) */
/* WARNING: Removing unreachable block (ram,0x007c3b39) */
/* WARNING: Removing unreachable block (ram,0x007c3b5a) */
/* WARNING: Removing unreachable block (ram,0x007c3b64) */
/* WARNING: Removing unreachable block (ram,0x007c3b69) */
/* WARNING: Removing unreachable block (ram,0x007c3b78) */
/* WARNING: Removing unreachable block (ram,0x007c3ba8) */
/* WARNING: Removing unreachable block (ram,0x007c3b91) */
/* WARNING: Removing unreachable block (ram,0x007c3bb4) */
/* WARNING: Removing unreachable block (ram,0x007c3bd1) */
/* WARNING: Removing unreachable block (ram,0x007c34e9) */
/* WARNING: Removing unreachable block (ram,0x007c34f0) */
/* WARNING: Removing unreachable block (ram,0x007c3501) */
/* WARNING: Removing unreachable block (ram,0x007c3503) */
/* WARNING: Removing unreachable block (ram,0x007c3938) */
/* WARNING: Removing unreachable block (ram,0x007c3943) */
/* WARNING: Removing unreachable block (ram,0x007c394b) */
/* WARNING: Removing unreachable block (ram,0x007c3951) */
/* WARNING: Removing unreachable block (ram,0x007c395f) */
/* WARNING: Removing unreachable block (ram,0x007c398f) */
/* WARNING: Removing unreachable block (ram,0x007c397b) */
/* WARNING: Removing unreachable block (ram,0x007c399c) */
/* WARNING: Removing unreachable block (ram,0x007c39bd) */
/* WARNING: Removing unreachable block (ram,0x007c39c7) */
/* WARNING: Removing unreachable block (ram,0x007c39cc) */
/* WARNING: Removing unreachable block (ram,0x007c39db) */
/* WARNING: Removing unreachable block (ram,0x007c3a0b) */
/* WARNING: Removing unreachable block (ram,0x007c39f4) */
/* WARNING: Removing unreachable block (ram,0x007c3a17) */
/* WARNING: Removing unreachable block (ram,0x007c3a34) */
/* WARNING: Removing unreachable block (ram,0x007c3c68) */
/* WARNING: Removing unreachable block (ram,0x007c3c70) */

void FUN_007c3440(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  void *pvVar4;
  int *piVar5;
  uint uVar6;
  uint *puVar7;
  undefined4 *in_ECX;
  undefined4 *puVar8;
  undefined4 *puVar9;
  uint *puVar10;
  int *piVar11;
  int *local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091caed;
  local_10 = ExceptionList;
  uVar6 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = IS3D::CAvatarBase::vftable;
  local_8 = 10;
  if (in_ECX[0x2f] != 0) {
    piVar11 = *(int **)in_ECX[0x2e];
    local_1c = piVar11;
    if (piVar11 != (int *)in_ECX[0x2e]) {
      do {
        iVar2 = piVar11[4];
        if (*(int *)(iVar2 + 0x38) != *(int *)(iVar2 + 0x3c)) {
          *(int *)(iVar2 + 0x3c) = *(int *)(iVar2 + 0x38);
        }
        local_18 = piVar11[4];
        iVar2 = *(int *)(local_18 + 0x28);
        if (iVar2 != *(int *)(local_18 + 0x2c)) {
          *(int *)(local_18 + 0x2c) = iVar2;
          piVar11 = local_1c;
          local_14 = iVar2;
        }
        iVar2 = piVar11[4];
        if (iVar2 != 0) {
          if (*(int *)(iVar2 + 0x38) != 0) {
            FUN_0089120c(*(int *)(iVar2 + 0x38),uVar6);
          }
          *(undefined4 *)(iVar2 + 0x38) = 0;
          *(undefined4 *)(iVar2 + 0x3c) = 0;
          *(undefined4 *)(iVar2 + 0x40) = 0;
          if (*(int *)(iVar2 + 0x28) != 0) {
            FUN_0089120c(*(int *)(iVar2 + 0x28),uVar6);
          }
          *(undefined4 *)(iVar2 + 0x28) = 0;
          *(undefined4 *)(iVar2 + 0x2c) = 0;
          *(undefined4 *)(iVar2 + 0x30) = 0;
          FUN_0089120c(iVar2,uVar6);
          piVar11[4] = 0;
        }
        if (*(char *)((int)piVar11 + 0x15) == '\0') {
          piVar3 = (int *)piVar11[2];
          if (*(char *)((int)piVar3 + 0x15) == '\0') {
            cVar1 = *(char *)(*piVar3 + 0x15);
            piVar11 = piVar3;
            piVar3 = (int *)*piVar3;
            while (local_1c = piVar11, cVar1 == '\0') {
              cVar1 = *(char *)(*piVar3 + 0x15);
              piVar11 = piVar3;
              piVar3 = (int *)*piVar3;
            }
          }
          else {
            cVar1 = *(char *)(piVar11[1] + 0x15);
            piVar5 = (int *)piVar11[1];
            piVar3 = piVar11;
            while ((piVar11 = piVar5, local_1c = piVar11, cVar1 == '\0' &&
                   (piVar3 == (int *)piVar11[2]))) {
              cVar1 = *(char *)(piVar11[1] + 0x15);
              piVar5 = (int *)piVar11[1];
              piVar3 = piVar11;
            }
          }
        }
      } while (piVar11 != (int *)in_ECX[0x2e]);
    }
    piVar11 = *(int **)(in_ECX[0x2e] + 4);
    cVar1 = *(char *)((int)piVar11 + 0x15);
    while (local_1c = piVar11, cVar1 == '\0') {
      FUN_0073eba0(piVar11[2]);
      piVar11 = (int *)*piVar11;
      FUN_0089120c(local_1c);
      cVar1 = *(char *)((int)piVar11 + 0x15);
    }
    *(undefined4 *)(in_ECX[0x2e] + 4) = in_ECX[0x2e];
    *(undefined4 *)in_ECX[0x2e] = in_ECX[0x2e];
    *(undefined4 *)(in_ECX[0x2e] + 8) = in_ECX[0x2e];
    in_ECX[0x2f] = 0;
  }
  if (in_ECX[0x37] != 0) {
    piVar11 = *(int **)in_ECX[0x36];
    if (piVar11 != (int *)in_ECX[0x36]) {
      do {
        if ((undefined4 *)piVar11[4] != (undefined4 *)0x0) {
          (*(code *)**(undefined4 **)piVar11[4])(1);
          piVar11[4] = 0;
        }
        if (*(char *)((int)piVar11 + 0x15) == '\0') {
          piVar3 = (int *)piVar11[2];
          if (*(char *)((int)piVar3 + 0x15) == '\0') {
            cVar1 = *(char *)(*piVar3 + 0x15);
            piVar11 = piVar3;
            piVar3 = (int *)*piVar3;
            while (cVar1 == '\0') {
              cVar1 = *(char *)(*piVar3 + 0x15);
              piVar11 = piVar3;
              piVar3 = (int *)*piVar3;
            }
          }
          else {
            cVar1 = *(char *)(piVar11[1] + 0x15);
            piVar5 = (int *)piVar11[1];
            piVar3 = piVar11;
            while ((piVar11 = piVar5, cVar1 == '\0' && (piVar3 == (int *)piVar11[2]))) {
              cVar1 = *(char *)(piVar11[1] + 0x15);
              piVar5 = (int *)piVar11[1];
              piVar3 = piVar11;
            }
          }
        }
      } while (piVar11 != (int *)in_ECX[0x36]);
    }
    piVar11 = *(int **)(in_ECX[0x36] + 4);
    cVar1 = *(char *)((int)piVar11 + 0x15);
    while (local_1c = piVar11, cVar1 == '\0') {
      FUN_0073eba0(piVar11[2]);
      piVar11 = (int *)*piVar11;
      FUN_0089120c(local_1c);
      cVar1 = *(char *)((int)piVar11 + 0x15);
    }
    *(undefined4 *)(in_ECX[0x36] + 4) = in_ECX[0x36];
    *(undefined4 *)in_ECX[0x36] = in_ECX[0x36];
    *(undefined4 *)(in_ECX[0x36] + 8) = in_ECX[0x36];
    in_ECX[0x37] = 0;
  }
  iVar2 = in_ECX[0x39];
  if (iVar2 != 0) {
    FUN_007d60b0(iVar2);
    FUN_0089120c(iVar2);
    in_ECX[0x39] = 0;
  }
  local_14 = 0;
  if ((int)(in_ECX[0x2a] - in_ECX[0x29]) >> 2 != 0) {
    do {
      iVar2 = *(int *)(in_ECX[0x29] + local_14 * 4);
      local_1c = (int *)0x0;
      if (*(int *)(iVar2 + 0x24) - *(int *)(iVar2 + 0x20) >> 2 != 0) {
        do {
          iVar2 = *(int *)(*(int *)(*(int *)(in_ECX[0x29] + local_14 * 4) + 0x20) +
                          (int)local_1c * 4);
          uVar6 = 0;
          if (*(int *)(iVar2 + 0x48) - *(int *)(iVar2 + 0x44) >> 2 != 0) {
            do {
              if (*(int *)(*(int *)(iVar2 + 0x44) + uVar6 * 4) != 0) {
                puVar8 = *(undefined4 **)(*(int *)(iVar2 + 0x44) + uVar6 * 4);
                if (puVar8 != (undefined4 *)0x0) {
                  (**(code **)*puVar8)(1);
                }
                *(undefined4 *)(*(int *)(iVar2 + 0x44) + uVar6 * 4) = 0;
              }
              uVar6 = uVar6 + 1;
            } while (uVar6 < (uint)(*(int *)(iVar2 + 0x48) - *(int *)(iVar2 + 0x44) >> 2));
          }
          if (iVar2 != 0) {
            if (*(int *)(iVar2 + 0x44) != 0) {
              FUN_0089120c(*(int *)(iVar2 + 0x44));
            }
            *(undefined4 *)(iVar2 + 0x44) = 0;
            *(undefined4 *)(iVar2 + 0x48) = 0;
            *(undefined4 *)(iVar2 + 0x4c) = 0;
            FUN_0089120c(iVar2);
          }
          iVar2 = *(int *)(in_ECX[0x29] + local_14 * 4);
          local_1c = (int *)((int)local_1c + 1);
        } while (local_1c < (int *)(*(int *)(iVar2 + 0x24) - *(int *)(iVar2 + 0x20) >> 2));
      }
      iVar2 = *(int *)(in_ECX[0x29] + local_14 * 4);
      pvVar4 = *(void **)(iVar2 + 0x20);
      if (pvVar4 != *(void **)(iVar2 + 0x24)) {
        local_1c = (int *)0x0;
        FID_conflict__memcpy(pvVar4,*(void **)(iVar2 + 0x24),0);
        *(int *)(iVar2 + 0x24) = (int)pvVar4 + (int)local_1c;
      }
      if (*(int *)(in_ECX[0x29] + local_14 * 4) != 0) {
        iVar2 = *(int *)(in_ECX[0x29] + local_14 * 4);
        if (iVar2 != 0) {
          if (*(int *)(iVar2 + 0x20) != 0) {
            FUN_0089120c(*(int *)(iVar2 + 0x20));
          }
          *(undefined4 *)(iVar2 + 0x20) = 0;
          *(undefined4 *)(iVar2 + 0x24) = 0;
          *(undefined4 *)(iVar2 + 0x28) = 0;
          FUN_0089120c(iVar2);
        }
        *(undefined4 *)(in_ECX[0x29] + local_14 * 4) = 0;
      }
      local_14 = local_14 + 1;
    } while (local_14 < (uint)((int)(in_ECX[0x2a] - in_ECX[0x29]) >> 2));
  }
  pvVar4 = (void *)in_ECX[0x29];
  if (pvVar4 != (void *)in_ECX[0x2a]) {
    FID_conflict__memcpy(pvVar4,(void *)in_ECX[0x2a],0);
    in_ECX[0x2a] = pvVar4;
  }
  puVar8 = (undefined4 *)in_ECX[0x21];
  if (puVar8 != (undefined4 *)in_ECX[0x22]) {
    puVar7 = puVar8 + 0xc;
    do {
      puVar7[-8] = 0;
      puVar9 = puVar8;
      if (0xf < puVar7[-7]) {
        puVar9 = (undefined4 *)*puVar8;
      }
      *(undefined1 *)puVar9 = 0;
      puVar7[-1] = 0;
      if (*puVar7 < 0x10) {
        puVar10 = puVar7 + -5;
      }
      else {
        puVar10 = (uint *)puVar7[-5];
      }
      puVar8 = puVar8 + 0xe;
      *(undefined1 *)puVar10 = 0;
      puVar7 = puVar7 + 0xe;
    } while (puVar8 != (undefined4 *)in_ECX[0x22]);
  }
  local_18 = in_ECX[0x22];
  uVar6 = in_ECX[0x21];
  if (uVar6 != local_18) {
    local_14 = uVar6;
    FUN_007b2b80(in_ECX);
    in_ECX[0x22] = uVar6;
  }
  puVar8 = (undefined4 *)in_ECX[0x25];
  if (puVar8 != (undefined4 *)in_ECX[0x26]) {
    puVar7 = puVar8 + 0xc;
    do {
      puVar7[-8] = 0;
      puVar9 = puVar8;
      if (0xf < puVar7[-7]) {
        puVar9 = (undefined4 *)*puVar8;
      }
      *(undefined1 *)puVar9 = 0;
      puVar7[-1] = 0;
      if (*puVar7 < 0x10) {
        puVar10 = puVar7 + -5;
      }
      else {
        puVar10 = (uint *)puVar7[-5];
      }
      puVar8 = puVar8 + 0xe;
      *(undefined1 *)puVar10 = 0;
      puVar7 = puVar7 + 0xe;
    } while (puVar8 != (undefined4 *)in_ECX[0x26]);
  }
  local_18 = in_ECX[0x26];
  uVar6 = in_ECX[0x25];
  if (uVar6 != local_18) {
    local_14 = uVar6;
    FUN_007b2b80(in_ECX);
    in_ECX[0x26] = uVar6;
  }
  puVar8 = (undefined4 *)in_ECX[0x31];
  if (puVar8 != (undefined4 *)in_ECX[0x32]) {
    puVar7 = puVar8 + 0xc;
    do {
      puVar7[-8] = 0;
      puVar9 = puVar8;
      if (0xf < puVar7[-7]) {
        puVar9 = (undefined4 *)*puVar8;
      }
      *(undefined1 *)puVar9 = 0;
      puVar7[-1] = 0;
      if (*puVar7 < 0x10) {
        puVar10 = puVar7 + -5;
      }
      else {
        puVar10 = (uint *)puVar7[-5];
      }
      puVar8 = puVar8 + 0xe;
      *(undefined1 *)puVar10 = 0;
      puVar7 = puVar7 + 0xe;
    } while (puVar8 != (undefined4 *)in_ECX[0x32]);
  }
  local_18 = in_ECX[0x32];
  iVar2 = in_ECX[0x31];
  if (iVar2 != local_18) {
    FUN_007b2b80(in_ECX);
    in_ECX[0x32] = iVar2;
  }
  FUN_00556160(in_ECX + 0x19,&local_1c,in_ECX[0x19],in_ECX[0x1a]);
  FUN_00556160(in_ECX + 0x1d,&local_1c,in_ECX[0x1d],in_ECX[0x1e]);
  if ((undefined4 *)in_ECX[0x3b] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x3b])(1);
    in_ECX[0x3b] = 0;
  }
  local_1c = in_ECX + 0x35;
  local_8 = CONCAT31(local_8._1_3_,0xb);
  FUN_005540c0(*(undefined4 *)in_ECX[0x36],(undefined4 *)in_ECX[0x36]);
  FUN_0089120c(in_ECX[0x36]);
  if (in_ECX[0x31] != 0) {
    FUN_007b2b80(in_ECX);
    FUN_0089120c(in_ECX[0x31]);
  }
  local_1c = in_ECX + 0x2d;
  in_ECX[0x31] = 0;
  in_ECX[0x32] = 0;
  in_ECX[0x33] = 0;
  local_8 = CONCAT31(local_8._1_3_,0xc);
  FUN_005540c0(*(undefined4 *)in_ECX[0x2e],(undefined4 *)in_ECX[0x2e]);
  FUN_0089120c(local_1c[1]);
  if (in_ECX[0x29] != 0) {
    FUN_0089120c(in_ECX[0x29]);
  }
  in_ECX[0x29] = 0;
  in_ECX[0x2a] = 0;
  in_ECX[0x2b] = 0;
  if (in_ECX[0x25] != 0) {
    FUN_007b2b80(in_ECX);
    FUN_0089120c(in_ECX[0x25]);
  }
  in_ECX[0x25] = 0;
  in_ECX[0x26] = 0;
  in_ECX[0x27] = 0;
  if (in_ECX[0x21] != 0) {
    FUN_007b2b80(in_ECX);
    FUN_0089120c(in_ECX[0x21]);
  }
  in_ECX[0x21] = 0;
  in_ECX[0x22] = 0;
  in_ECX[0x23] = 0;
  puVar8 = (undefined4 *)in_ECX[0x1d];
  if (puVar8 != (undefined4 *)0x0) {
    puVar9 = (undefined4 *)in_ECX[0x1e];
    for (; puVar8 != puVar9; puVar8 = puVar8 + 7) {
      if (0xf < (uint)puVar8[5]) {
        FUN_0089120c(*puVar8);
      }
      puVar8[5] = 0xf;
      puVar8[4] = 0;
      *(undefined1 *)puVar8 = 0;
    }
    FUN_0089120c(in_ECX[0x1d]);
  }
  in_ECX[0x1d] = 0;
  in_ECX[0x1e] = 0;
  in_ECX[0x1f] = 0;
  puVar8 = (undefined4 *)in_ECX[0x19];
  if (puVar8 != (undefined4 *)0x0) {
    puVar9 = (undefined4 *)in_ECX[0x1a];
    for (; puVar8 != puVar9; puVar8 = puVar8 + 7) {
      if (0xf < (uint)puVar8[5]) {
        FUN_0089120c(*puVar8);
      }
      puVar8[5] = 0xf;
      puVar8[4] = 0;
      *(undefined1 *)puVar8 = 0;
    }
    FUN_0089120c(in_ECX[0x19]);
  }
  in_ECX[0x19] = 0;
  in_ECX[0x1a] = 0;
  in_ECX[0x1b] = 0;
  if (0xf < (uint)in_ECX[0x14]) {
    FUN_0089120c(in_ECX[0xf]);
  }
  in_ECX[0x14] = 0xf;
  in_ECX[0x13] = 0;
  *(undefined1 *)(in_ECX + 0xf) = 0;
  if (0xf < (uint)in_ECX[0xd]) {
    FUN_0089120c(in_ECX[8]);
  }
  in_ECX[0xd] = 0xf;
  in_ECX[0xc] = 0;
  *(undefined1 *)(in_ECX + 8) = 0;
  if (0xf < (uint)in_ECX[6]) {
    FUN_0089120c(in_ECX[1]);
  }
  in_ECX[6] = 0xf;
  in_ECX[5] = 0;
  *(undefined1 *)(in_ECX + 1) = 0;
  ExceptionList = local_10;
  return;
}

