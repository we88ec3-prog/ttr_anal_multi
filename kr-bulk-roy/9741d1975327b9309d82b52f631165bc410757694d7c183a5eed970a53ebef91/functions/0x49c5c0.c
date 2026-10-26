
void FUN_0049c5c0(int *param_1)

{
  ushort uVar1;
  undefined4 *puVar2;
  DWORD DVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  uint uVar8;
  int *piVar9;
  char *in_ECX;
  int iVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 *local_7c;
  char cStack_75;
  undefined4 *local_74;
  int local_70;
  undefined4 *puStack_68;
  int iStack_64;
  char *local_5c [2];
  char *local_54;
  undefined4 uStack_50;
  char *local_4c;
  undefined4 uStack_48;
  char *pcStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined **local_34 [3];
  undefined **local_28 [3];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  int local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00940f94;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_7c;
  ExceptionList = &local_14;
  local_7c = (undefined4 *)0x0;
  local_4c = (char *)0x0;
  local_70 = 0;
  local_5c[0] = in_ECX;
  local_74 = (undefined4 *)FUN_00891268(0xc,DAT_00d61f20 ^ (uint)&stack0xffffff78);
  if (local_74 == (undefined4 *)0x0) {
    local_54 = (char *)0x0;
    std::exception::exception((exception *)local_34,&local_54);
    local_34[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_34,&DAT_00c857a8);
  }
  *local_74 = local_74;
  local_74[1] = local_74;
  local_c = 0;
  if ((param_1 != (int *)0x0) && (FUN_0049d470(), local_70 != 0)) {
    iVar10 = param_1[1];
    if ((DAT_00fdf6dc & 1) == 0) {
      DAT_00fdf6dc = DAT_00fdf6dc | 1;
      local_c._0_1_ = 1;
      FUN_00550820();
      _atexit((_func_4879 *)&LAB_00bce6b0);
      local_c = (uint)local_c._1_3_ << 8;
    }
    local_7c = (undefined4 *)(**(code **)(*param_1 + 0x50))(local_28);
    FUN_00551b80(0xffffffff,0xffffffff);
    FUN_00551dd0(&DAT_00fdf680,(short)iVar10,local_7c,0,0x3f800000,1);
    FUN_0049d010();
  }
  puVar7 = local_74;
  local_c = 0xffffffff;
  puVar4 = (undefined4 *)*local_74;
  *local_74 = local_74;
  local_74[1] = local_74;
  while (puVar4 != puVar7) {
    local_7c = (undefined4 *)*puVar4;
    FUN_0089120c(puVar4);
    puVar4 = local_7c;
  }
  FUN_0089120c(puVar7);
  if ((DAT_00fb7c14 & 1) == 0) {
    DAT_00fb7c14 = DAT_00fb7c14 | 1;
    local_c = 2;
    FUN_006d0750();
    _atexit((_func_4879 *)&LAB_00bcd530);
    local_c = 0xffffffff;
  }
  if (DAT_00fb901b == '\0') {
    FUN_005571c0(in_ECX);
LAB_0049cc33:
    in_ECX[0x24] = '\0';
    in_ECX[0x25] = '\0';
    in_ECX[0x26] = '\0';
    in_ECX[0x27] = '\0';
  }
  else {
    if (DAT_00fb901b == '\x01') {
      DVar3 = timeGetTime();
      *(DWORD *)(in_ECX + 0x20) = DVar3;
      local_4c = (char *)0x1;
      in_ECX[0x1c] = '\x01';
      in_ECX[0x1d] = '\0';
      in_ECX[0x1e] = '\0';
      in_ECX[0x1f] = '\0';
      iStack_64 = 0;
      puStack_68 = (undefined4 *)FUN_00891268(0xc);
      if (puStack_68 == (undefined4 *)0x0) {
        local_5c[0] = (char *)0x0;
        std::exception::exception((exception *)local_34,local_5c);
        local_34[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8(local_34,&DAT_00c857a8);
      }
      *puStack_68 = puStack_68;
      puStack_68[1] = puStack_68;
      local_c = 3;
      iVar10 = 0;
      local_70 = 0;
      puVar4 = (undefined4 *)FUN_00891268(0xc);
      if (puVar4 == (undefined4 *)0x0) {
        local_54 = (char *)0x0;
        std::exception::exception((exception *)local_28,&local_54);
        local_28[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8(local_28,&DAT_00c857a8);
      }
      *puVar4 = puVar4;
      puVar4[1] = puVar4;
      local_c = CONCAT31(local_c._1_3_,4);
      local_74 = puVar4;
      if (param_1 != (int *)0x0) {
        FUN_0049ce10(&puStack_68,0);
      }
      local_7c = (undefined4 *)*puStack_68;
      puVar7 = puVar4;
      if (local_7c != puStack_68) {
        do {
          local_5c[0] = (char *)local_7c[2];
          if (*(int *)(local_5c[0] + 0x11c) == 0) {
            iVar5 = FUN_0074d700(puVar4,puVar4[1],local_5c);
            if (iVar10 == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
              FUN_0087db30("list<T> too long");
            }
            puVar4[1] = iVar5;
            iVar10 = iVar10 + 1;
            **(int **)(iVar5 + 4) = iVar5;
            puVar7 = local_74;
            local_70 = iVar10;
          }
          local_7c = (undefined4 *)*local_7c;
        } while (local_7c != puStack_68);
        puVar4 = puVar7;
        if (iVar10 != 0) {
          iVar10 = param_1[1];
          uStack_48 = 2;
          pcStack_44 = "GETITEM";
          uStack_40 = 0xffffffff;
          uStack_3c = 0xffffffff;
          uStack_38 = 0;
          if ((DAT_00fdf6dc & 1) == 0) {
            DAT_00fdf6dc = DAT_00fdf6dc | 1;
            local_c._0_1_ = 5;
            FUN_00550820();
            _atexit((_func_4879 *)&LAB_00bce6b0);
            local_c = CONCAT31(local_c._1_3_,4);
          }
          uVar12 = 0x3f800000;
          uVar11 = 0;
          uVar6 = (**(code **)(*param_1 + 0x50))(local_34,0,0x3f800000);
          FUN_00551f20((short)iVar10,uVar6,uVar11,uVar12);
          FUN_0049d010();
          puVar4 = local_74;
        }
      }
      puVar7 = (undefined4 *)*puVar4;
      *puVar4 = puVar4;
      puVar4[1] = puVar4;
      if (puVar7 != puVar4) {
        do {
          puVar2 = (undefined4 *)*puVar7;
          FUN_0089120c(puVar7);
          puVar7 = puVar2;
          puVar4 = local_74;
        } while (puVar2 != local_74);
      }
      FUN_0089120c(puVar4);
      puVar7 = puStack_68;
      puVar4 = (undefined4 *)*puStack_68;
      *puStack_68 = puStack_68;
      puStack_68[1] = puStack_68;
      while (puVar4 != puVar7) {
        puVar2 = (undefined4 *)*puVar4;
        FUN_0089120c(puVar4);
        puVar4 = puVar2;
      }
      FUN_0089120c(puVar7);
      goto LAB_0049cc39;
    }
    if (DAT_00fb901b == '\x02') {
      DVar3 = timeGetTime();
      if (((600 < DVar3 - *(int *)(in_ECX + 0x20)) && (*(int *)(in_ECX + 0x1c) != 0)) &&
         ((iVar10 = FUN_00404ba0(), *(int *)(iVar10 + 0x5f4c) == 9 ||
          (iVar10 = FUN_00404ba0(), *(int *)(iVar10 + 0x5f4c) == 4)))) {
        in_ECX[0x24] = '\x01';
        in_ECX[0x25] = '\0';
        in_ECX[0x26] = '\0';
        in_ECX[0x27] = '\0';
        FUN_0049d640();
        local_c = 6;
        if (param_1 != (int *)0x0) {
          FUN_0049ce10(&puStack_68,1);
        }
        FUN_00556df0(in_ECX,&puStack_68);
        iVar10 = FUN_00444960();
        if ((*(char *)(iVar10 + 0x7e9) == '\x01') &&
           (*(int *)(in_ECX + 0x10) = *(int *)(in_ECX + 0x10) + 1,
           *(int *)(in_ECX + 8) <= *(int *)(in_ECX + 0x10))) {
          in_ECX[0x10] = -1;
          in_ECX[0x11] = -1;
          in_ECX[0x12] = -1;
          in_ECX[0x13] = -1;
        }
        iVar10 = FUN_00444960();
        if ((*(char *)(iVar10 + 0x7ea) == '\x01') &&
           (*(int *)(in_ECX + 0x10) = *(int *)(in_ECX + 0x10) + -1, *(int *)(in_ECX + 0x10) < -1)) {
          *(int *)(in_ECX + 0x10) = *(int *)(in_ECX + 8) + -1;
        }
        FUN_005572a0(in_ECX);
        FUN_0056fb00();
      }
      goto LAB_0049cc39;
    }
    if (DAT_00fb901b != '\x03') goto LAB_0049cc39;
    DVar3 = timeGetTime();
    if (600 < DVar3 - *(int *)(in_ECX + 0x20)) {
      if (*(int *)(in_ECX + 0x24) != 0) {
        FUN_0049d640();
        local_c = 7;
        local_54 = (char *)FUN_00557180();
        if (local_54 != (char *)0x0) {
          FUN_0074a200();
          FUN_0049d010();
          in_ECX = local_5c[0];
          if (iStack_64 != 0) {
            uVar12 = 0x3f800000;
            uVar11 = 0x10;
            (**(code **)(*param_1 + 0x68))(0x10,0x3f800000);
            uVar1 = *(ushort *)(param_1 + 1);
            uStack_48 = 0xffffffff;
            pcStack_44 = (char *)0xffffffff;
            uStack_50 = 2;
            local_4c = "GETITEM";
            uStack_40 = 0;
            uVar6 = (**(code **)(*param_1 + 0x50))(&uStack_3c,0,0x3f800000);
            uVar8 = (uint)uVar1;
            FUN_0049b140(uVar8,uVar6);
            FUN_00551f20(uVar8,uVar6,uVar11,uVar12);
            in_ECX = local_5c[0];
          }
        }
        FUN_005571c0(in_ECX);
        FUN_0056fb00();
      }
      goto LAB_0049cc33;
    }
    if (param_1[0xe3] == 0x10) goto LAB_0049cc36;
    piVar9 = (int *)FUN_0049c3d0();
    local_c = 8;
    local_7c = (undefined4 *)0x1;
    if (*piVar9 == 0) {
LAB_0049cbc6:
      cStack_75 = '\0';
    }
    else {
      FUN_0049c3d0();
      local_c = 9;
      local_7c = (undefined4 *)0x3;
      iVar10 = FUN_007a7800(0x10);
      cStack_75 = '\x01';
      if (iVar10 == 0) goto LAB_0049cbc6;
    }
    local_c = 8;
    if (((uint)local_7c & 2) != 0) {
      local_7c = (undefined4 *)((uint)local_7c & 0xfffffffd);
      FUN_007a1050();
    }
    local_c = 0xffffffff;
    if (((uint)local_7c & 1) != 0) {
      FUN_007a1050();
    }
    if (cStack_75 != '\0') {
      (**(code **)(*param_1 + 0x68))(0x10,0x3f800000);
      FUN_0049cc90();
      local_4c = (char *)0x1;
    }
  }
LAB_0049cc36:
  in_ECX[0x1c] = '\0';
  in_ECX[0x1d] = '\0';
  in_ECX[0x1e] = '\0';
  in_ECX[0x1f] = '\0';
LAB_0049cc39:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_7c);
  return;
}

