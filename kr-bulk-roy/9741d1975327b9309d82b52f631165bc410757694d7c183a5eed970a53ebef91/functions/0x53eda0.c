
void FUN_0053eda0(void)

{
  int **ppiVar1;
  int **ppiVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  undefined4 *puVar7;
  uint *puVar8;
  int iVar9;
  char *_Str1;
  int iVar10;
  uint uVar11;
  int *_Str1_00;
  undefined4 uVar12;
  uint uVar13;
  uint *puVar14;
  undefined1 auStack_bc [4];
  int *piStack_b8;
  int *apiStack_b4 [4];
  uint *puStack_a4;
  undefined1 auStack_a0 [8];
  undefined **local_98 [19];
  uint local_4c;
  undefined4 uStack_3c;
  uint local_38;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009231cb;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_bc;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xffffff38;
  ExceptionList = &local_14;
  FUN_0072ee30(local_98);
  local_c = 0;
  cVar3 = FUN_0072f110(0);
  if ((cVar3 != '\0') && (iVar5 = FUN_0072e2e0("ShoutTable"), iVar5 != 0)) {
    piVar6 = (int *)FUN_0072e2e0("Monster");
    apiStack_b4[1] = piVar6;
    while (piVar6 != (int *)0x0) {
      iVar5 = (**(code **)(*piVar6 + 0x14))();
      if (iVar5 != 0) {
        iVar5 = FUN_007300a0(&DAT_00c0f49c);
        if (iVar5 == 0) {
LAB_0053ee85:
          apiStack_b4[2] = (int *)0x0;
        }
        else {
          puVar7 = (undefined4 *)(iVar5 + 0x30);
          if (0xf < *(uint *)(iVar5 + 0x44)) {
            puVar7 = (undefined4 *)*puVar7;
          }
          if (puVar7 == (undefined4 *)0x0) goto LAB_0053ee85;
          apiStack_b4[2] = (int *)FUN_008917b4(puVar7);
        }
        puVar8 = (uint *)FUN_00891268(0x10);
        puVar14 = (uint *)0x0;
        if (puVar8 != (uint *)0x0) {
          *puVar8 = 0;
          puVar8[1] = 0;
          puVar8[2] = 0;
          puVar14 = puVar8;
        }
        piVar6 = (int *)FUN_0072e2e0("Shout");
joined_r0x0053eeb3:
        piStack_b8 = piVar6;
        if (piStack_b8 != (int *)0x0) {
          iVar9 = (**(code **)(*piStack_b8 + 0x14))();
          for (iVar5 = *(int *)(iVar9 + 0x94); iVar5 != iVar9 + 0x44; iVar5 = *(int *)(iVar5 + 0x50)
              ) {
            _Str1 = (char *)(iVar5 + 0x14);
            if (0xf < *(uint *)(iVar5 + 0x28)) {
              _Str1 = *(char **)_Str1;
            }
            iVar10 = __stricmp(_Str1,"talkidx");
            if (iVar10 == 0) {
              if (iVar5 != 0) {
                puVar7 = (undefined4 *)(iVar5 + 0x30);
                if (0xf < *(uint *)(iVar5 + 0x44)) {
                  puVar7 = (undefined4 *)*puVar7;
                }
                if (puVar7 != (undefined4 *)0x0) {
                  piVar6 = (int *)FUN_008917b4(puVar7);
                  goto LAB_0053ef06;
                }
              }
              break;
            }
          }
          piVar6 = (int *)0x0;
LAB_0053ef06:
          ppiVar1 = (int **)puVar14[1];
          apiStack_b4[0] = piVar6;
          if ((apiStack_b4 < ppiVar1) && (ppiVar2 = (int **)*puVar14, ppiVar2 <= apiStack_b4)) {
            if (ppiVar1 == (int **)puVar14[2]) {
              uVar11 = (int)ppiVar1 - (int)ppiVar2 >> 2;
              if (0x3ffffffe < uVar11) {
LAB_0053f0e3:
                    /* WARNING: Subroutine does not return */
                FUN_0087db30("vector<T> too long");
              }
              uVar11 = uVar11 + 1;
              uVar13 = (int)puVar14[2] - (int)ppiVar2 >> 2;
              if (uVar13 < uVar11) {
                if (0x3fffffff - (uVar13 >> 1) < uVar13) {
                  uVar13 = 0;
                }
                else {
                  uVar13 = uVar13 + (uVar13 >> 1);
                }
                if (uVar13 < uVar11) {
                  uVar13 = uVar11;
                }
                FUN_00797980(uVar13);
              }
            }
            if ((undefined4 *)puVar14[1] != (undefined4 *)0x0) {
              *(undefined4 *)puVar14[1] =
                   *(undefined4 *)(*puVar14 + ((int)apiStack_b4 - (int)ppiVar2 >> 2) * 4);
            }
          }
          else {
            if (ppiVar1 == (int **)puVar14[2]) {
              uVar11 = (int)((int)ppiVar1 - *puVar14) >> 2;
              if (0x3ffffffe < uVar11) goto LAB_0053f0e3;
              uVar11 = uVar11 + 1;
              uVar13 = (int)((int)puVar14[2] - *puVar14) >> 2;
              if (uVar13 < uVar11) {
                if (0x3fffffff - (uVar13 >> 1) < uVar13) {
                  uVar13 = 0;
                }
                else {
                  uVar13 = uVar13 + (uVar13 >> 1);
                }
                if (uVar13 < uVar11) {
                  uVar13 = uVar11;
                }
                FUN_00797980(uVar13);
              }
            }
            if ((undefined4 *)puVar14[1] != (undefined4 *)0x0) {
              *(undefined4 *)puVar14[1] = piVar6;
            }
          }
          puVar14[1] = puVar14[1] + 4;
          for (piVar6 = (int *)piStack_b8[0x10]; piVar6 != (int *)0x0; piVar6 = (int *)piVar6[0x10])
          {
            _Str1_00 = piVar6 + 8;
            if (0xf < (uint)piVar6[0xd]) {
              _Str1_00 = (int *)*_Str1_00;
            }
            iVar5 = __stricmp((char *)_Str1_00,"Shout");
            if (iVar5 == 0) goto joined_r0x0053eeb3;
          }
          piVar6 = (int *)0x0;
          goto joined_r0x0053eeb3;
        }
        apiStack_b4[3] = apiStack_b4[2];
        puStack_a4 = puVar14;
        uVar12 = FUN_0053f900();
        FUN_0053f610(auStack_a0,uVar12);
        piVar6 = (int *)FUN_0072e320("Monster");
        apiStack_b4[1] = piVar6;
      }
    }
  }
  local_c = 0xffffffff;
  local_98[0] = TiXmlDocument::vftable;
  if (0xf < local_38) {
    FUN_0089120c(local_4c,uVar4);
  }
  local_38 = 0xf;
  uStack_3c = 0;
  local_4c = local_4c & 0xffffff00;
  FUN_0072e040();
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_bc);
  return;
}

