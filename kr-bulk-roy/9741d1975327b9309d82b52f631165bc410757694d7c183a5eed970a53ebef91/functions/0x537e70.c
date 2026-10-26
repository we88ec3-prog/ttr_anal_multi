
undefined4 FUN_00537e70(int param_1,int param_2,int *param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  bool bVar7;
  undefined **local_38 [3];
  undefined4 local_2c;
  char *local_24;
  int local_20;
  undefined4 local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00916eb1;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = 0;
  uVar5 = param_3[1] - *param_3 >> 3;
  local_18 = uVar5;
  if (uVar5 != 0) {
    do {
      iVar1 = *(int *)(*param_3 + 4 + local_14 * 8);
      local_2c = *(undefined4 *)(*param_3 + local_14 * 8);
      iVar6 = param_2;
      if ((*(int *)(param_2 + 0x60) == 0) ||
         (((iVar4 = *(int *)(param_2 + 8), iVar4 != 0x1c && (iVar4 != 0x10)) && (iVar4 != 0x19)))) {
        iVar4 = param_2;
        if ((*(int *)(param_2 + 8) == 0x2c) && (*(int *)(param_1 + 0x60) != 0)) {
          uVar2 = *(undefined4 *)(*(int *)(param_1 + 0x60) + 8);
          if ((DAT_00f8d9a4 & 1) == 0) {
            DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
            local_8 = 2;
            FUN_0051c120(uVar3);
            _atexit((_func_4879 *)&LAB_00bccc90);
            local_8 = 0xffffffff;
          }
          iVar4 = FUN_0051d700(uVar2);
          goto switchD_00537f9e_caseD_5;
        }
      }
      else {
        if ((DAT_00f8d9a8 & 1) == 0) {
          DAT_00f8d9a8 = DAT_00f8d9a8 | 1;
          local_8 = 0;
          DAT_00f8d9b4 = 0;
          iVar4 = FUN_00891268(0x18);
          if (iVar4 == 0) {
            local_24 = (char *)0x0;
            std::exception::exception((exception *)local_38,&local_24);
            local_38[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
            __CxxThrowException_8(local_38,&DAT_00c857a8);
          }
          DAT_00f8d9b0 = iVar4;
          *(int *)iVar4 = iVar4;
          *(int *)(DAT_00f8d9b0 + 4) = DAT_00f8d9b0;
          *(int *)(DAT_00f8d9b0 + 8) = DAT_00f8d9b0;
          *(undefined1 *)(DAT_00f8d9b0 + 0x14) = 1;
          *(undefined1 *)(DAT_00f8d9b0 + 0x15) = 1;
          local_8 = CONCAT31(local_8._1_3_,1);
          FUN_00521080(&DAT_00f8d9bc);
          _atexit((_func_4879 *)&LAB_00bccc50);
          local_8 = 0xffffffff;
        }
        local_1c = *(undefined4 *)(param_2 + 0x60);
        FUN_008438c0(&local_1c);
        if (local_20 == DAT_00f8d9b0) {
          iVar4 = 0;
        }
        else {
          iVar4 = *(int *)(local_20 + 0x10);
          if (iVar4 != 0) {
            switch(*(undefined4 *)(iVar4 + 8)) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 0x11:
            case 0x12:
            case 0x13:
            case 0x1b:
            case 0x20:
            case 0x24:
            case 0x25:
            case 0x28:
            case 0x29:
            case 0x2a:
            case 0x2b:
              iVar6 = iVar4;
            }
          }
        }
switchD_00537f9e_caseD_5:
        uVar5 = local_18;
      }
      switch(local_2c) {
      case 0:
        bVar7 = iVar1 == *(int *)(param_1 + 0x20);
        break;
      case 1:
        bVar7 = iVar1 == *(int *)(param_1 + 0x1c);
        break;
      case 2:
        if (iVar1 != *(int *)(iVar6 + 4)) {
          iVar6 = *(int *)(iVar4 + 4);
joined_r0x00538078:
          if (iVar1 != iVar6) {
            ExceptionList = local_10;
            return 0;
          }
        }
        goto LAB_0053801d;
      case 3:
        bVar7 = iVar1 == *(int *)(iVar6 + 8);
        break;
      case 4:
        bVar7 = iVar1 == *(int *)(iVar6 + 0x5c);
        break;
      case 5:
        bVar7 = iVar1 == *(int *)(iVar6 + 0x58);
        break;
      case 6:
        bVar7 = iVar1 == *(int *)(param_2 + 0x60);
        break;
      case 7:
        if (iVar1 != *(int *)(param_2 + 100)) {
          iVar6 = *(int *)(iVar4 + 8);
          goto joined_r0x00538078;
        }
        goto LAB_0053801d;
      case 8:
        if (*(int *)(iVar6 + 0x78) < iVar1) {
          ExceptionList = local_10;
          return 0;
        }
        if (*(int *)(iVar6 + 0x78) == 0) {
          ExceptionList = local_10;
          return 0;
        }
        bVar7 = *(int *)(iVar6 + 0x7c) == 0;
        goto LAB_0053801b;
      case 9:
        if (iVar1 < *(int *)(iVar6 + 0x7c)) {
          ExceptionList = local_10;
          return 0;
        }
        if (*(int *)(iVar6 + 0x78) == 0) {
          ExceptionList = local_10;
          return 0;
        }
        bVar7 = *(int *)(iVar6 + 0x7c) == 0;
        goto LAB_0053801b;
      default:
        goto switchD_00538009_default;
      }
      bVar7 = !bVar7;
LAB_0053801b:
      if (bVar7) {
switchD_00538009_default:
        ExceptionList = local_10;
        return 0;
      }
LAB_0053801d:
      local_14 = local_14 + 1;
    } while (local_14 < uVar5);
  }
  ExceptionList = local_10;
  return 1;
}

