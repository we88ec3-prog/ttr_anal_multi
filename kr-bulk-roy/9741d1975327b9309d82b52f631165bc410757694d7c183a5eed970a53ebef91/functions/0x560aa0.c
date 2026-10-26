
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00560aa0(int param_1)

{
  char cVar1;
  ushort uVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  int *piVar12;
  int *piVar13;
  int *local_5c;
  uint local_54;
  int local_50;
  int local_4c;
  int local_48;
  int iStack_44;
  int local_40;
  int iStack_3c;
  char *pcStack_38;
  int *local_34;
  undefined **local_30 [3];
  undefined **appuStack_24 [4];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093ad4e;
  local_14 = ExceptionList;
  uVar6 = DAT_00d61f20 ^ (uint)&stack0xffffff98;
  ExceptionList = &local_14;
  local_34 = *(int **)(param_1 + 0x1c);
  piVar13 = (int *)*local_34;
  local_5c = piVar13;
  if (piVar13 != local_34) {
    do {
      local_30[0] = (undefined **)piVar13[3];
      piVar3 = (int *)piVar13[4];
      if (*(int *)(param_1 + 0x70) != 0) {
        uVar2 = *(ushort *)(piVar3 + 0x22);
        if ((DAT_00fc0f60 & 1) == 0) {
          DAT_00fc0f60 = DAT_00fc0f60 | 1;
          local_c = 0;
          FUN_0079cf40(uVar6);
          _atexit((_func_4879 *)&LAB_00bcdb80);
          local_c = 0xffffffff;
        }
        local_54 = (uint)uVar2;
        FUN_00515790(&local_54);
        if ((local_50 != DAT_00fc0e94) &&
           (iVar9 = *(int *)(*(int *)(local_50 + 0x10) + 0x54), local_40 = iVar9, iVar9 != 0)) {
          local_54 = 1;
          FUN_0082ef00(&local_54);
          iVar10 = local_4c;
          if ((local_4c != *(int *)(iVar9 + 0xd8)) &&
             (iVar7 = (**(code **)(**(int **)(local_4c + 0x10) + 8))(), iVar7 == 1)) {
            (**(code **)(**(int **)(iVar10 + 0x10) + 0x24))();
          }
          local_54 = 4;
          FUN_0082ef00(&local_54);
          iVar10 = local_48;
          if ((local_48 != *(int *)(iVar9 + 0xd8)) &&
             (iVar7 = (**(code **)(**(int **)(local_48 + 0x10) + 8))(), iVar7 == 4)) {
            (**(code **)(**(int **)(iVar10 + 0x10) + 0x24))();
          }
          local_54 = (uint)local_30[0] & 0xffff;
          iVar10 = *(int *)(param_1 + 0x70);
          FUN_00826280(&local_54);
          piVar13 = local_5c;
          if (iStack_44 != *(int *)(iVar10 + 4)) {
            pcStack_38 = *(char **)(iStack_44 + 0x10);
            piVar12 = (int *)**(int **)(pcStack_38 + 8);
            if (piVar12 != *(int **)(pcStack_38 + 8)) {
              do {
                uVar2 = *(ushort *)(piVar12 + 3);
                local_54 = (uint)uVar2;
                FUN_0082ef00(&local_54);
                iVar10 = iStack_3c;
                if ((iStack_3c != *(int *)(iVar9 + 0xd8)) &&
                   (uVar8 = (**(code **)(**(int **)(iStack_3c + 0x10) + 8))(), uVar8 == uVar2)) {
                  (**(code **)(**(int **)(iVar10 + 0x10) + 0x24))();
                }
                if (*(char *)((int)piVar12 + 0xf) == '\0') {
                  piVar4 = (int *)piVar12[2];
                  if (*(char *)((int)piVar4 + 0xf) == '\0') {
                    cVar1 = *(char *)(*piVar4 + 0xf);
                    piVar12 = piVar4;
                    piVar4 = (int *)*piVar4;
                    while (cVar1 == '\0') {
                      cVar1 = *(char *)(*piVar4 + 0xf);
                      piVar12 = piVar4;
                      piVar4 = (int *)*piVar4;
                    }
                  }
                  else {
                    cVar1 = *(char *)(piVar12[1] + 0xf);
                    piVar5 = (int *)piVar12[1];
                    piVar4 = piVar12;
                    while ((piVar12 = piVar5, cVar1 == '\0' && (piVar4 == (int *)piVar12[2]))) {
                      cVar1 = *(char *)(piVar12[1] + 0xf);
                      piVar5 = (int *)piVar12[1];
                      piVar4 = piVar12;
                    }
                  }
                }
                iVar9 = local_40;
              } while (piVar12 != *(int **)(pcStack_38 + 8));
            }
          }
        }
      }
      (**(code **)(*piVar3 + 0x10))();
      if (*(char *)((int)piVar13 + 0x15) == '\0') {
        piVar3 = (int *)piVar13[2];
        if (*(char *)((int)piVar3 + 0x15) == '\0') {
          cVar1 = *(char *)(*piVar3 + 0x15);
          piVar13 = piVar3;
          piVar3 = (int *)*piVar3;
          while (local_5c = piVar13, cVar1 == '\0') {
            cVar1 = *(char *)(*piVar3 + 0x15);
            piVar13 = piVar3;
            piVar3 = (int *)*piVar3;
          }
        }
        else {
          cVar1 = *(char *)(piVar13[1] + 0x15);
          piVar12 = (int *)piVar13[1];
          piVar3 = piVar13;
          while ((piVar13 = piVar12, local_5c = piVar13, cVar1 == '\0' &&
                 (piVar3 == (int *)piVar13[2]))) {
            cVar1 = *(char *)(piVar13[1] + 0x15);
            piVar12 = (int *)piVar13[1];
            piVar3 = piVar13;
          }
        }
      }
    } while (piVar13 != local_34);
  }
  if ((_DAT_00fe38cc & 1) == 0) {
    _DAT_00fe38cc = _DAT_00fe38cc | 1;
    _DAT_00fe36e4 = 0x400;
    _DAT_00fe36e8 = 0x300;
    _DAT_00fe36ec = 0;
    _atexit((_func_4879 *)&DAT_00bcf2d0);
  }
  local_34 = (int *)FUN_00891268(0x48);
  local_c = 1;
  if (local_34 == (int *)0x0) {
    iVar9 = 0;
  }
  else {
    iVar9 = FUN_00734010();
  }
  uVar6 = DAT_00fcde40 & 1;
  DAT_00fe36e0 = iVar9;
  *(undefined4 *)(iVar9 + 0xc) = 0x10;
  *(undefined4 *)(iVar9 + 0x10) = 0x80;
  *(undefined4 *)(iVar9 + 0x1c) = 0x15;
  if (uVar6 == 0) {
    DAT_00fcde40 = DAT_00fcde40 | 1;
    local_c = 2;
    DAT_00fcde28 = 0;
    DAT_00fcde2c = 0;
    _DAT_00fcde38 = 0;
    iVar10 = FUN_00891268(0x30);
    if (iVar10 == 0) {
      local_34 = (int *)0x0;
      std::exception::exception((exception *)local_30,(char **)&local_34);
      local_30[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_30,&DAT_00c857a8);
    }
    DAT_00fcde34 = iVar10;
    *(int *)iVar10 = iVar10;
    *(int *)(DAT_00fcde34 + 4) = DAT_00fcde34;
    *(int *)(DAT_00fcde34 + 8) = DAT_00fcde34;
    *(undefined1 *)(DAT_00fcde34 + 0x2c) = 1;
    *(undefined1 *)(DAT_00fcde34 + 0x2d) = 1;
    _atexit(FUN_00bce6f0);
  }
  local_c = 0xffffffff;
  uVar11 = D3DXCreateTexture(DAT_00fcde2c,0x10,0x80,1,0,0x15,1,iVar9 + 0x44);
  FUN_00733f90(uVar11,0);
  FUN_00734470(DAT_00fe36e0,0xff000000);
  if ((DAT_00fe2740 & 1) == 0) {
    DAT_00fe2740 = DAT_00fe2740 | 1;
    local_c = 3;
    FUN_0055e680();
    _atexit((_func_4879 *)&DAT_00bcf2a0);
    local_c = 0xffffffff;
  }
  local_34 = (int *)FUN_00891268(0x48);
  local_c = 4;
  if (local_34 == (int *)0x0) {
    iVar9 = 0;
  }
  else {
    iVar9 = FUN_00734010();
  }
  uVar6 = DAT_00fcde40 & 1;
  DAT_00fe2744 = iVar9;
  *(undefined4 *)(iVar9 + 0xc) = 0x20;
  *(undefined4 *)(iVar9 + 0x10) = 0x20;
  *(undefined4 *)(iVar9 + 0x1c) = 0x15;
  if (uVar6 == 0) {
    DAT_00fcde40 = DAT_00fcde40 | 1;
    local_c = 5;
    DAT_00fcde28 = 0;
    DAT_00fcde2c = 0;
    _DAT_00fcde38 = 0;
    iVar10 = FUN_00891268(0x30);
    if (iVar10 == 0) {
      pcStack_38 = (char *)0x0;
      std::exception::exception((exception *)appuStack_24,&pcStack_38);
      appuStack_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(appuStack_24,&DAT_00c857a8);
    }
    DAT_00fcde34 = iVar10;
    *(int *)iVar10 = iVar10;
    *(int *)(DAT_00fcde34 + 4) = DAT_00fcde34;
    *(int *)(DAT_00fcde34 + 8) = DAT_00fcde34;
    *(undefined1 *)(DAT_00fcde34 + 0x2c) = 1;
    *(undefined1 *)(DAT_00fcde34 + 0x2d) = 1;
    _atexit(FUN_00bce6f0);
  }
  local_c = 0xffffffff;
  uVar11 = D3DXCreateTexture(DAT_00fcde2c,0x20,0x20,1,0,0x15,1,iVar9 + 0x44);
  FUN_00733f90(uVar11,0);
  FUN_00734470(DAT_00fe2744,0xff000000);
  ExceptionList = local_14;
  return 0;
}

