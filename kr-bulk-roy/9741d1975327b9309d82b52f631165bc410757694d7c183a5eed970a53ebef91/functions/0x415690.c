
void FUN_00415690(void)

{
  char cVar1;
  void *_Dst;
  int **ppiVar2;
  int **ppiVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 **ppuVar10;
  int *piVar11;
  int *piVar12;
  undefined4 *puVar13;
  int in_EDX;
  undefined4 *puVar14;
  int *piVar15;
  uint uVar16;
  undefined1 auStack_74 [4];
  int *apiStack_70 [2];
  int local_68;
  undefined4 *puStack_64;
  undefined4 uStack_60;
  undefined4 *apuStack_5c [3];
  uint uStack_50;
  undefined4 uStack_40;
  uint uStack_3c;
  undefined4 uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_009344f4;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_74;
  uVar7 = DAT_00d61f20 ^ (uint)&stack0xffffff80;
  ExceptionList = &local_14;
  apiStack_70[1] = (int *)(*(int *)(in_EDX + 0x1b4) - *(int *)(in_EDX + 0x1b0) >> 2);
  if (apiStack_70[1] == (int *)0x0) {
    apiStack_70[1] = (int *)0x4;
  }
  _Dst = *(void **)(in_EDX + 0xb8);
  local_68 = in_EDX;
  if (_Dst != *(void **)(in_EDX + 0xbc)) {
    FID_conflict__memcpy(_Dst,*(void **)(in_EDX + 0xbc),0);
    *(void **)(in_EDX + 0xbc) = _Dst;
  }
  iVar8 = *(int *)(*(int *)(local_68 + 0xb4) + 0xcc);
  if (iVar8 != 0) {
    FUN_00408920(iVar8,apiStack_70[1]);
  }
  uVar16 = 0;
  if (apiStack_70[1] != (int *)0x0) {
    do {
      iVar8 = *(int *)(*(int *)(local_68 + 0xb4) + 0xcc);
      if ((((iVar8 == 0) || ((int)uVar16 < 0)) ||
          (*(int *)(iVar8 + 0xac) - *(int *)(iVar8 + 0xa8) >> 2 <= (int)uVar16)) ||
         (piVar15 = *(int **)(*(int *)(iVar8 + 0xa8) + uVar16 * 4), piVar15 == (int *)0x0)) {
LAB_004157ad:
        piVar15 = (int *)0x0;
      }
      else {
        iVar8 = (**(code **)(*piVar15 + 4))(uVar7);
        if (iVar8 != 0x12d) {
          MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
          goto LAB_004157ad;
        }
      }
      ppiVar2 = *(int ***)(in_EDX + 0xbc);
      apiStack_70[0] = piVar15;
      if (apiStack_70 < ppiVar2) {
        ppiVar3 = *(int ***)(in_EDX + 0xb8);
        if (apiStack_70 < ppiVar3) goto LAB_004157ed;
        if (ppiVar2 == *(int ***)(in_EDX + 0xc0)) {
          FUN_004deab0();
        }
        if (*(undefined4 **)(in_EDX + 0xbc) != (undefined4 *)0x0) {
          **(undefined4 **)(in_EDX + 0xbc) =
               *(undefined4 *)
                (*(uint *)(in_EDX + 0xb8) + ((int)apiStack_70 - (int)ppiVar3 >> 2) * 4);
        }
      }
      else {
LAB_004157ed:
        if (ppiVar2 == *(int ***)(in_EDX + 0xc0)) {
          FUN_004deab0();
        }
        if (*(int **)(in_EDX + 0xbc) != (int *)0x0) {
          **(int **)(in_EDX + 0xbc) = (int)piVar15;
        }
      }
      *(int *)(in_EDX + 0xbc) = *(int *)(in_EDX + 0xbc) + 4;
      uVar16 = uVar16 + 1;
    } while (uVar16 < apiStack_70[1]);
  }
  iVar8 = *(int *)(*(int *)(local_68 + 0xb4) + 0xcc);
  if (iVar8 != 0) {
    *(undefined1 *)(iVar8 + 0xe0) = 0;
  }
  piVar15 = *(int **)(local_68 + 0xb4);
  puVar14 = (undefined4 *)piVar15[0x19];
  for (puVar9 = (undefined4 *)*puVar14; puVar9 != puVar14; puVar9 = (undefined4 *)*puVar9) {
    iVar8 = puVar9[2];
    if ((*(int *)(iVar8 + 0x60) != 0) && ((*(int **)(iVar8 + 0x1c))[2] != 6)) {
      (**(code **)(**(int **)(iVar8 + 0x1c) + 0x30))(iVar8);
    }
  }
  (**(code **)(*piVar15 + 0x128))();
  iVar8 = local_68;
  (**(code **)(**(int **)(local_68 + 0xb4) + 200))();
  apiStack_70[1] = (int *)0x0;
  if (*(int *)(iVar8 + 0x1b4) - *(int *)(iVar8 + 0x1b0) >> 2 != 0) {
    apiStack_70[0] = (int *)0x0;
    puVar14 = DAT_00f8d91c;
    do {
      piVar15 = *(int **)(*(int *)(iVar8 + 0x1b0) + (int)apiStack_70[1] * 4);
      if (piVar15[0x15] != piVar15[0x16]) {
        uStack_60 = *(undefined4 *)(piVar15[0x15] + 8);
        piVar11 = *(int **)((int)apiStack_70[0] + *(int *)(iVar8 + 0xb8));
        if ((DAT_00f8d9a4 & 1) == 0) {
          DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
          uStack_c = 0;
          FUN_0051c120();
          _atexit((_func_4879 *)&LAB_00bccc90);
          uStack_c = 0xffffffff;
          puVar14 = DAT_00f8d91c;
        }
        cVar1 = *(char *)((int)puVar14[1] + 0x15);
        puVar9 = (undefined4 *)puVar14[1];
        puStack_64 = puVar14;
        while (puVar13 = puVar9, cVar1 == '\0') {
          if ((int)puVar13[3] < *piVar15) {
            puVar9 = (undefined4 *)puVar13[2];
            puVar13 = puStack_64;
          }
          else {
            puVar9 = (undefined4 *)*puVar13;
          }
          cVar1 = *(char *)((int)puVar9 + 0x15);
          puStack_64 = puVar13;
        }
        if ((puStack_64 == puVar14) || (*piVar15 < (int)puStack_64[3])) {
          apuStack_5c[0] = puVar14;
          ppuVar10 = apuStack_5c;
        }
        else {
          ppuVar10 = &puStack_64;
        }
        if ((*ppuVar10 != puVar14) && (iVar8 = (*ppuVar10)[4], iVar8 != 0)) {
          if ((DAT_00fab100 & 1) == 0) {
            DAT_00fab100 = DAT_00fab100 | 1;
            uStack_c = 1;
            FUN_0049d6a0();
            _atexit((_func_4879 *)&LAB_00bcce20);
            uStack_c = 0xffffffff;
          }
          FUN_00757f20();
          uVar4 = *(undefined4 *)(iVar8 + 0x1c);
          iVar5 = piVar11[0x92];
          uVar6 = *(undefined4 *)(iVar8 + 0x20);
          *(undefined1 *)(iVar5 + 0x269) = 1;
          *(undefined4 *)(iVar5 + 0x26c) = 0;
          *(undefined4 *)(iVar5 + 0x270) = 0;
          *(undefined4 *)(iVar5 + 0x274) = 0;
          (**(code **)(*(int *)piVar11[0x92] + 0x19c))(uVar6,uVar4,0,0);
          iVar8 = piVar15[8];
          (**(code **)(*(int *)piVar11[0x93] + 0x94))(iVar8 == 3);
          (**(code **)(*(int *)piVar11[0x94] + 0x94))(iVar8 == 4);
          FUN_00757710();
          FUN_00412df0();
          uStack_24 = 3;
          FUN_00757710();
          uStack_24 = 0xffffffff;
          if ((undefined4 *)0x7 < apuStack_5c[0]) {
            FUN_0089120c(apiStack_70[0]);
          }
          apiStack_70[0] = (int *)((uint)apiStack_70[0] & 0xffff0000);
          apuStack_5c[0] = (undefined4 *)0x7;
          uStack_60 = 0;
          FUN_004026e0(piVar15 + 0xe,0,0xffffffff);
          uStack_24 = 4;
          FUN_00757800(apiStack_70);
          (**(code **)(*(int *)piVar11[0x96] + 200))();
          uStack_24 = 0xffffffff;
          if ((undefined4 *)0x7 < apuStack_5c[0]) {
            FUN_0089120c(apiStack_70[0]);
          }
          (**(code **)(*piVar11 + 0x90))(1);
          apiStack_70[0] = apiStack_70[0] + 1;
          puVar14 = DAT_00f8d91c;
        }
      }
      apiStack_70[1] = (int *)((int)apiStack_70[1] + 1);
      iVar8 = local_68;
    } while (apiStack_70[1] < (int *)(*(int *)(local_68 + 0x1b4) - *(int *)(local_68 + 0x1b0) >> 2))
    ;
  }
  if ((*(int *)(local_68 + 0x1b4) - *(int *)(local_68 + 0x1b0) & 0xfffffffcU) == 0) {
    apiStack_70[0] = (int *)0x0;
    do {
      piVar15 = *(int **)((int)apiStack_70[0] + *(int *)(local_68 + 0xb8));
      piVar15[0x3e] = 0;
      if ((uint)piVar15[0x3f] < 8) {
        piVar11 = piVar15 + 0x3a;
      }
      else {
        piVar11 = (int *)piVar15[0x3a];
      }
      *(undefined2 *)piVar11 = 0;
      piVar11 = (int *)piVar15[0x41];
      piVar12 = (int *)*piVar11;
      *piVar11 = (int)piVar11;
      *(int *)(piVar15[0x41] + 4) = piVar15[0x41];
      piVar15[0x42] = 0;
      if (piVar12 != (int *)piVar15[0x41]) {
        do {
          piVar11 = (int *)*piVar12;
          FUN_0089120c(piVar12);
          piVar12 = piVar11;
        } while (piVar11 != (int *)piVar15[0x41]);
      }
      piVar11 = *(int **)(piVar15[0x45] + 4);
      cVar1 = *(char *)((int)piVar11 + 0x21);
      while (apiStack_70[1] = piVar11, cVar1 == '\0') {
        FUN_008575b0(piVar11[2]);
        piVar11 = (int *)*piVar11;
        FUN_0089120c(apiStack_70[1]);
        cVar1 = *(char *)((int)piVar11 + 0x21);
      }
      *(int *)(piVar15[0x45] + 4) = piVar15[0x45];
      *(int *)piVar15[0x45] = piVar15[0x45];
      *(int *)(piVar15[0x45] + 8) = piVar15[0x45];
      piVar15[0x46] = 0;
      iVar8 = piVar15[0x92];
      *(undefined1 *)(iVar8 + 0x269) = 1;
      *(undefined4 *)(iVar8 + 0x26c) = 0;
      *(undefined4 *)(iVar8 + 0x270) = 0;
      *(undefined4 *)(iVar8 + 0x274) = 0;
      (**(code **)(*(int *)piVar15[0x92] + 0x19c))(0xffffffff,0xffffffff,0,0);
      (**(code **)(*(int *)piVar15[0x93] + 0x94))(0);
      (**(code **)(*(int *)piVar15[0x94] + 0x94))(0);
      FUN_00757710();
      FUN_00412df0();
      uStack_24 = 5;
      FUN_00757710();
      uStack_24 = 0xffffffff;
      if (7 < uStack_3c) {
        FUN_0089120c(uStack_50);
      }
      uStack_50 = uStack_50 & 0xffff0000;
      uStack_3c = 7;
      uStack_40 = 0;
      (**(code **)(*piVar15 + 0x90))(0);
      apiStack_70[0] = apiStack_70[0] + 1;
    } while (apiStack_70[0] < (int *)0x10);
  }
  (**(code **)(**(int **)(local_68 + 0xb4) + 200))();
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_74);
  return;
}

