
uint FUN_00729a20(uint param_1)

{
  char cVar1;
  undefined4 *puVar2;
  int *piVar3;
  bool bVar4;
  undefined1 uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int *unaff_EDI;
  uint local_8;
  
  if (((unaff_EDI == (int *)0x0) ||
      (puVar2 = (undefined4 *)unaff_EDI[7], puVar2 == (undefined4 *)0x0)) || (4 < param_1)) {
    return 0xfffffffe;
  }
  if (((unaff_EDI[3] == 0) || ((*unaff_EDI == 0 && (unaff_EDI[1] != 0)))) ||
     ((puVar2[1] == 0x29a && (param_1 != 4)))) {
    unaff_EDI[6] = (int)"stream error";
    return 0xfffffffe;
  }
  if (unaff_EDI[4] == 0) {
    unaff_EDI[6] = (int)"buffer error";
    return 0xfffffffb;
  }
  iVar9 = puVar2[10];
  *puVar2 = unaff_EDI;
  puVar2[10] = param_1;
  if (puVar2[1] == 0x2a) {
    if (puVar2[6] == 2) {
      unaff_EDI[0xc] = 0;
      *(undefined1 *)(puVar2[5] + puVar2[2]) = 0x1f;
      puVar2[5] = puVar2[5] + 1;
      *(undefined1 *)(puVar2[5] + puVar2[2]) = 0x8b;
      puVar2[5] = puVar2[5] + 1;
      *(undefined1 *)(puVar2[5] + puVar2[2]) = 8;
      puVar2[5] = puVar2[5] + 1;
      piVar3 = (int *)puVar2[7];
      if (piVar3 == (int *)0x0) {
        *(undefined1 *)(puVar2[5] + puVar2[2]) = 0;
        puVar2[5] = puVar2[5] + 1;
        *(undefined1 *)(puVar2[5] + puVar2[2]) = 0;
        puVar2[5] = puVar2[5] + 1;
        *(undefined1 *)(puVar2[5] + puVar2[2]) = 0;
        puVar2[5] = puVar2[5] + 1;
        *(undefined1 *)(puVar2[5] + puVar2[2]) = 0;
        puVar2[5] = puVar2[5] + 1;
        *(undefined1 *)(puVar2[5] + puVar2[2]) = 0;
        puVar2[5] = puVar2[5] + 1;
        if (puVar2[0x21] == 9) {
          uVar5 = 2;
        }
        else if (((int)puVar2[0x22] < 2) && (1 < (int)puVar2[0x21])) {
          uVar5 = 0;
        }
        else {
          uVar5 = 4;
        }
        *(undefined1 *)(puVar2[5] + puVar2[2]) = uVar5;
        puVar2[5] = puVar2[5] + 1;
        *(undefined1 *)(puVar2[5] + puVar2[2]) = 0xb;
        puVar2[5] = puVar2[5] + 1;
        puVar2[1] = 0x71;
      }
      else {
        *(byte *)(puVar2[5] + puVar2[2]) =
             (-(piVar3[9] != 0) & 0x10U) + (-(piVar3[0xb] != 0) & 2U) + (-(piVar3[7] != 0) & 8U) +
             (-(piVar3[4] != 0) & 4U) + (*piVar3 != 0);
        puVar2[5] = puVar2[5] + 1;
        *(undefined1 *)(puVar2[5] + puVar2[2]) = *(undefined1 *)(puVar2[7] + 4);
        puVar2[5] = puVar2[5] + 1;
        *(undefined1 *)(puVar2[5] + puVar2[2]) = *(undefined1 *)(puVar2[7] + 5);
        puVar2[5] = puVar2[5] + 1;
        *(undefined1 *)(puVar2[5] + puVar2[2]) = *(undefined1 *)(puVar2[7] + 6);
        puVar2[5] = puVar2[5] + 1;
        *(undefined1 *)(puVar2[5] + puVar2[2]) = *(undefined1 *)(puVar2[7] + 7);
        puVar2[5] = puVar2[5] + 1;
        if (puVar2[0x21] == 9) {
          uVar5 = 2;
        }
        else if (((int)puVar2[0x22] < 2) && (1 < (int)puVar2[0x21])) {
          uVar5 = 0;
        }
        else {
          uVar5 = 4;
        }
        *(undefined1 *)(puVar2[5] + puVar2[2]) = uVar5;
        puVar2[5] = puVar2[5] + 1;
        *(undefined1 *)(puVar2[5] + puVar2[2]) = *(undefined1 *)(puVar2[7] + 0xc);
        puVar2[5] = puVar2[5] + 1;
        iVar6 = puVar2[5];
        if (*(int *)(puVar2[7] + 0x10) != 0) {
          *(undefined1 *)(iVar6 + puVar2[2]) = *(undefined1 *)(puVar2[7] + 0x14);
          puVar2[5] = puVar2[5] + 1;
          *(undefined1 *)(puVar2[5] + puVar2[2]) = *(undefined1 *)(puVar2[7] + 0x15);
          puVar2[5] = puVar2[5] + 1;
          iVar6 = puVar2[5];
        }
        if (*(int *)(puVar2[7] + 0x2c) != 0) {
          iVar6 = FUN_0072b6e0(unaff_EDI[0xc],iVar6);
          unaff_EDI[0xc] = iVar6;
        }
        puVar2[8] = 0;
        puVar2[1] = 0x45;
      }
    }
    else {
      puVar2[1] = 0x71;
      FUN_007299a0();
      if (puVar2[0x1b] != 0) {
        FUN_007299a0();
        FUN_007299a0();
      }
      unaff_EDI[0xc] = 1;
    }
  }
  if (puVar2[1] == 0x45) {
    if (*(int *)(puVar2[7] + 0x10) != 0) {
      local_8 = puVar2[5];
      if ((uint)puVar2[8] < (uint)*(ushort *)(puVar2[7] + 0x14)) {
        do {
          uVar7 = puVar2[5];
          if (uVar7 == puVar2[3]) {
            if ((*(int *)(puVar2[7] + 0x2c) != 0) && (local_8 < uVar7)) {
              iVar6 = FUN_0072b6e0(unaff_EDI[0xc],uVar7 - local_8);
              unaff_EDI[0xc] = iVar6;
            }
            FUN_007299d0();
            uVar7 = puVar2[5];
            local_8 = uVar7;
            if (uVar7 == puVar2[3]) break;
          }
          *(undefined1 *)(uVar7 + puVar2[2]) =
               *(undefined1 *)(*(int *)(puVar2[7] + 0x10) + puVar2[8]);
          puVar2[5] = puVar2[5] + 1;
          puVar2[8] = puVar2[8] + 1;
        } while ((uint)puVar2[8] < (uint)*(ushort *)(puVar2[7] + 0x14));
      }
      if ((*(int *)(puVar2[7] + 0x2c) != 0) && (local_8 < (uint)puVar2[5])) {
        iVar6 = FUN_0072b6e0(unaff_EDI[0xc],puVar2[5] - local_8);
        unaff_EDI[0xc] = iVar6;
      }
      if (puVar2[8] != *(int *)(puVar2[7] + 0x14)) goto LAB_00729e02;
      puVar2[8] = 0;
    }
    puVar2[1] = 0x49;
  }
LAB_00729e02:
  if (puVar2[1] == 0x49) {
    if (*(int *)(puVar2[7] + 0x1c) != 0) {
      uVar7 = puVar2[5];
      do {
        uVar8 = puVar2[5];
        if (uVar8 == puVar2[3]) {
          if ((*(int *)(puVar2[7] + 0x2c) != 0) && (uVar7 < uVar8)) {
            iVar6 = FUN_0072b6e0(unaff_EDI[0xc],uVar8 - uVar7);
            unaff_EDI[0xc] = iVar6;
          }
          FUN_007299d0();
          uVar8 = puVar2[5];
          uVar7 = uVar8;
          if (uVar8 == puVar2[3]) {
            bVar4 = true;
            goto LAB_00729e82;
          }
        }
        cVar1 = *(char *)(*(int *)(puVar2[7] + 0x1c) + puVar2[8]);
        puVar2[8] = puVar2[8] + 1;
        *(char *)(uVar8 + puVar2[2]) = cVar1;
        puVar2[5] = puVar2[5] + 1;
      } while (cVar1 != '\0');
      bVar4 = false;
      uVar8 = uVar7;
LAB_00729e82:
      if ((*(int *)(puVar2[7] + 0x2c) != 0) && (uVar8 < (uint)puVar2[5])) {
        iVar6 = FUN_0072b6e0(unaff_EDI[0xc],puVar2[5] - uVar8);
        unaff_EDI[0xc] = iVar6;
      }
      if (bVar4) goto LAB_00729eb7;
      puVar2[8] = 0;
    }
    puVar2[1] = 0x5b;
  }
LAB_00729eb7:
  if (puVar2[1] == 0x5b) {
    if (*(int *)(puVar2[7] + 0x24) != 0) {
      uVar7 = puVar2[5];
      do {
        uVar8 = puVar2[5];
        if (uVar8 == puVar2[3]) {
          if ((*(int *)(puVar2[7] + 0x2c) != 0) && (uVar7 < uVar8)) {
            iVar6 = FUN_0072b6e0(unaff_EDI[0xc],uVar8 - uVar7);
            unaff_EDI[0xc] = iVar6;
          }
          FUN_007299d0();
          uVar8 = puVar2[5];
          uVar7 = uVar8;
          if (uVar8 == puVar2[3]) {
            bVar4 = true;
            goto LAB_00729f33;
          }
        }
        cVar1 = *(char *)(*(int *)(puVar2[7] + 0x24) + puVar2[8]);
        puVar2[8] = puVar2[8] + 1;
        *(char *)(uVar8 + puVar2[2]) = cVar1;
        puVar2[5] = puVar2[5] + 1;
      } while (cVar1 != '\0');
      bVar4 = false;
      uVar8 = uVar7;
LAB_00729f33:
      if ((*(int *)(puVar2[7] + 0x2c) != 0) && (uVar8 < (uint)puVar2[5])) {
        iVar6 = FUN_0072b6e0(unaff_EDI[0xc],puVar2[5] - uVar8);
        unaff_EDI[0xc] = iVar6;
      }
      if (bVar4) goto LAB_00729f65;
    }
    puVar2[1] = 0x67;
  }
LAB_00729f65:
  if (puVar2[1] == 0x67) {
    if (*(int *)(puVar2[7] + 0x2c) != 0) {
      if ((uint)puVar2[3] < puVar2[5] + 2) {
        FUN_007299d0();
      }
      if ((uint)puVar2[3] < puVar2[5] + 2) goto LAB_00729fbf;
      *(char *)(puVar2[5] + puVar2[2]) = (char)unaff_EDI[0xc];
      puVar2[5] = puVar2[5] + 1;
      *(undefined1 *)(puVar2[5] + puVar2[2]) = *(undefined1 *)((int)unaff_EDI + 0x31);
      puVar2[5] = puVar2[5] + 1;
      unaff_EDI[0xc] = 0;
    }
    puVar2[1] = 0x71;
  }
LAB_00729fbf:
  if (puVar2[5] == 0) {
    if (((unaff_EDI[1] == 0) && ((int)param_1 <= iVar9)) && (param_1 != 4)) goto LAB_0072a004;
LAB_00729ff4:
    if (puVar2[1] == 0x29a) {
      if (unaff_EDI[1] != 0) {
LAB_0072a004:
        unaff_EDI[6] = (int)"buffer error";
        return 0xfffffffb;
      }
LAB_0072a01c:
      if ((puVar2[0x1d] != 0) || ((param_1 != 0 && (puVar2[1] != 0x29a)))) goto LAB_0072a037;
    }
    else {
      if (unaff_EDI[1] == 0) goto LAB_0072a01c;
LAB_0072a037:
      iVar9 = (*(code *)(&PTR_FUN_00c0ad28)[puVar2[0x21] * 3])(puVar2,param_1);
      if ((iVar9 == 2) || (iVar9 == 3)) {
        puVar2[1] = 0x29a;
      }
      if ((iVar9 == 0) || (iVar9 == 2)) {
        if (unaff_EDI[4] != 0) {
          return 0;
        }
        puVar2[10] = 0xffffffff;
        return 0;
      }
      if (iVar9 == 1) {
        if (param_1 == 1) {
          FUN_0072cf00();
        }
        else {
          FUN_0072ce60(0,0);
          if (param_1 == 3) {
            *(undefined2 *)(puVar2[0x11] + -2 + puVar2[0x13] * 2) = 0;
            _memset((void *)puVar2[0x11],0,puVar2[0x13] * 2 - 2);
          }
        }
        FUN_007299d0();
        if (unaff_EDI[4] == 0) goto LAB_00729fd2;
      }
    }
    if (param_1 == 4) {
      if ((int)puVar2[6] < 1) {
        return 1;
      }
      if (puVar2[6] == 2) {
        *(char *)(puVar2[5] + puVar2[2]) = (char)unaff_EDI[0xc];
        puVar2[5] = puVar2[5] + 1;
        *(undefined1 *)(puVar2[5] + puVar2[2]) = *(undefined1 *)((int)unaff_EDI + 0x31);
        puVar2[5] = puVar2[5] + 1;
        *(undefined1 *)(puVar2[5] + puVar2[2]) = *(undefined1 *)((int)unaff_EDI + 0x32);
        puVar2[5] = puVar2[5] + 1;
        *(undefined1 *)(puVar2[5] + puVar2[2]) = *(undefined1 *)((int)unaff_EDI + 0x33);
        puVar2[5] = puVar2[5] + 1;
        *(char *)(puVar2[5] + puVar2[2]) = (char)unaff_EDI[2];
        puVar2[5] = puVar2[5] + 1;
        *(undefined1 *)(puVar2[5] + puVar2[2]) = *(undefined1 *)((int)unaff_EDI + 9);
        puVar2[5] = puVar2[5] + 1;
        *(undefined1 *)(puVar2[5] + puVar2[2]) = *(undefined1 *)((int)unaff_EDI + 10);
        puVar2[5] = puVar2[5] + 1;
        *(undefined1 *)(puVar2[5] + puVar2[2]) = *(undefined1 *)((int)unaff_EDI + 0xb);
        puVar2[5] = puVar2[5] + 1;
      }
      else {
        FUN_007299a0();
        FUN_007299a0();
      }
      FUN_007299d0();
      if (0 < (int)puVar2[6]) {
        puVar2[6] = -puVar2[6];
      }
      return (uint)(puVar2[5] == 0);
    }
  }
  else {
    FUN_007299d0();
    if (unaff_EDI[4] != 0) goto LAB_00729ff4;
LAB_00729fd2:
    puVar2[10] = 0xffffffff;
  }
  return 0;
}

