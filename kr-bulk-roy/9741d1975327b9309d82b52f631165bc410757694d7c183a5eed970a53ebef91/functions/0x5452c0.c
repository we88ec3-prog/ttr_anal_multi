
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005452c0(void)

{
  undefined1 uVar1;
  uint uVar2;
  char cVar3;
  undefined4 *puVar4;
  undefined4 **ppuVar5;
  int iVar6;
  int *in_ECX;
  undefined4 *puVar7;
  int iVar8;
  int *piVar9;
  uint uVar10;
  uint uStack_3c;
  uint local_38;
  undefined4 *puStack_34;
  undefined4 *puStack_30;
  int local_2c;
  undefined4 uStack_28;
  undefined2 uStack_24;
  undefined4 uStack_20;
  undefined1 uStack_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00943f1c;
  local_14 = ExceptionList;
  if (in_ECX[1] == 0) {
    return 0;
  }
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffb0);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  local_2c = DAT_00f9423c;
  local_38 = DAT_00f9423c - in_ECX[0x19];
  FUN_0054ceb0();
  piVar9 = in_ECX + 4;
  iVar8 = 3;
  do {
    if (*piVar9 != 0) {
      FUN_0054f200();
      if ((piVar9[-1] != 0) && (*(int *)(*(int *)(piVar9[-1] + 0x158) + 8) == 3)) {
        FUN_00597b70();
      }
    }
    piVar9 = piVar9 + 3;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  uVar10 = 0;
  if (in_ECX[0xd] - in_ECX[0xc] >> 3 != 0) {
    do {
      iVar8 = in_ECX[0xc];
      if ((DAT_00fab22c & 1) == 0) {
        DAT_00fab22c = DAT_00fab22c | 1;
        local_c = 1;
        FUN_004dec90();
        _atexit((_func_4879 *)&LAB_00bcce30);
        local_c = 0xffffffff;
      }
      puVar4 = (undefined4 *)DAT_00fab13c[1];
      cVar3 = *(char *)((int)puVar4 + 0x15);
      while (cVar3 == '\0') {
        if ((uint)puVar4[3] < (uint)*(ushort *)(iVar8 + uVar10 * 8)) {
          puVar4 = (undefined4 *)puVar4[2];
        }
        else {
          puVar4 = (undefined4 *)*puVar4;
        }
        cVar3 = *(char *)((int)puVar4 + 0x15);
      }
      uVar10 = uVar10 + 1;
    } while (uVar10 < (uint)(in_ECX[0xd] - in_ECX[0xc] >> 3));
  }
  if (in_ECX[0x1e] != 0) goto LAB_00545b7d;
  if ((DAT_00fb7c14 & 1) == 0) {
    DAT_00fb7c14 = DAT_00fb7c14 | 1;
    local_c = 2;
    FUN_006d0750();
    _atexit((_func_4879 *)&LAB_00bcd530);
    local_c = 0xffffffff;
  }
  if (DAT_00fb9011 == '\x01') {
LAB_00545480:
    *(ushort *)(in_ECX + 0x17) = *(ushort *)(in_ECX + 0x17) | 1;
  }
  else {
    if ((DAT_00fb7c14 & 1) == 0) {
      DAT_00fb7c14 = DAT_00fb7c14 | 1;
      local_c = 3;
      FUN_006d0750();
      _atexit((_func_4879 *)&LAB_00bcd530);
      local_c = 0xffffffff;
    }
    if (DAT_00fb9011 == '\x02') goto LAB_00545480;
  }
  if ((DAT_00fb7c14 & 1) == 0) {
    DAT_00fb7c14 = DAT_00fb7c14 | 1;
    local_c = 4;
    FUN_006d0750();
    _atexit((_func_4879 *)&LAB_00bcd530);
    local_c = 0xffffffff;
  }
  if (DAT_00fb9012 == '\x01') {
LAB_005454fd:
    *(ushort *)(in_ECX + 0x17) = *(ushort *)(in_ECX + 0x17) | 2;
  }
  else {
    if ((DAT_00fb7c14 & 1) == 0) {
      DAT_00fb7c14 = DAT_00fb7c14 | 1;
      local_c = 5;
      FUN_006d0750();
      _atexit((_func_4879 *)&LAB_00bcd530);
      local_c = 0xffffffff;
    }
    if (DAT_00fb9012 == '\x02') goto LAB_005454fd;
  }
  if ((DAT_00fb7c14 & 1) == 0) {
    DAT_00fb7c14 = DAT_00fb7c14 | 1;
    local_c = 6;
    FUN_006d0750();
    _atexit((_func_4879 *)&LAB_00bcd530);
    local_c = 0xffffffff;
  }
  if (DAT_00fb9013 == '\x01') {
LAB_00545578:
    *(ushort *)(in_ECX + 0x17) = *(ushort *)(in_ECX + 0x17) | 4;
  }
  else {
    if ((DAT_00fb7c14 & 1) == 0) {
      DAT_00fb7c14 = DAT_00fb7c14 | 1;
      local_c = 7;
      FUN_006d0750();
      _atexit((_func_4879 *)&LAB_00bcd530);
      local_c = 0xffffffff;
    }
    if (DAT_00fb9013 == '\x02') goto LAB_00545578;
  }
  if ((DAT_00fb7c14 & 1) == 0) {
    DAT_00fb7c14 = DAT_00fb7c14 | 1;
    local_c = 8;
    FUN_006d0750();
    _atexit((_func_4879 *)&LAB_00bcd530);
    local_c = 0xffffffff;
  }
  if (DAT_00fb901a == '\x01') {
LAB_005455f2:
    *(ushort *)(in_ECX + 0x17) = *(ushort *)(in_ECX + 0x17) | 0x10;
  }
  else {
    if ((DAT_00fb7c14 & 1) == 0) {
      DAT_00fb7c14 = DAT_00fb7c14 | 1;
      local_c = 9;
      FUN_006d0750();
      _atexit((_func_4879 *)&LAB_00bcd530);
      local_c = 0xffffffff;
    }
    if (DAT_00fb901a == '\x02') goto LAB_005455f2;
  }
  if ((DAT_00fb7c14 & 1) == 0) {
    DAT_00fb7c14 = DAT_00fb7c14 | 1;
    local_c = 10;
    FUN_006d0750();
    _atexit((_func_4879 *)&LAB_00bcd530);
    local_c = 0xffffffff;
  }
  if (DAT_00fb901c == '\x01') {
LAB_0054566d:
    *(ushort *)(in_ECX + 0x17) = *(ushort *)(in_ECX + 0x17) | 3;
  }
  else {
    if ((DAT_00fb7c14 & 1) == 0) {
      DAT_00fb7c14 = DAT_00fb7c14 | 1;
      local_c = 0xb;
      FUN_006d0750();
      _atexit((_func_4879 *)&LAB_00bcd530);
      local_c = 0xffffffff;
    }
    if (DAT_00fb901c == '\x02') goto LAB_0054566d;
  }
  if ((DAT_00fb7c14 & 1) == 0) {
    DAT_00fb7c14 = DAT_00fb7c14 | 1;
    local_c = 0xc;
    FUN_006d0750();
    _atexit((_func_4879 *)&LAB_00bcd530);
    local_c = 0xffffffff;
  }
  if (DAT_00fb901d == '\x01') {
LAB_005456e8:
    *(ushort *)(in_ECX + 0x17) = *(ushort *)(in_ECX + 0x17) | 6;
  }
  else {
    if ((DAT_00fb7c14 & 1) == 0) {
      DAT_00fb7c14 = DAT_00fb7c14 | 1;
      local_c = 0xd;
      FUN_006d0750();
      _atexit((_func_4879 *)&LAB_00bcd530);
      local_c = 0xffffffff;
    }
    if (DAT_00fb901d == '\x02') goto LAB_005456e8;
  }
  if ((DAT_00fb7c14 & 1) == 0) {
    DAT_00fb7c14 = DAT_00fb7c14 | 1;
    local_c = 0xe;
    FUN_006d0750();
    _atexit((_func_4879 *)&LAB_00bcd530);
    local_c = 0xffffffff;
  }
  if (DAT_00fb901e == '\x01') {
LAB_00545763:
    *(ushort *)(in_ECX + 0x17) = *(ushort *)(in_ECX + 0x17) | 5;
  }
  else {
    if ((DAT_00fb7c14 & 1) == 0) {
      DAT_00fb7c14 = DAT_00fb7c14 | 1;
      local_c = 0xf;
      FUN_006d0750();
      _atexit((_func_4879 *)&LAB_00bcd530);
      local_c = 0xffffffff;
    }
    if (DAT_00fb901e == '\x02') goto LAB_00545763;
  }
  cVar3 = (**(code **)(*in_ECX + 0x18))();
  if (cVar3 == '\0') {
    iVar8 = in_ECX[6];
    if ((iVar8 != 0) && (*(int *)(iVar8 + 0x3a8) != 0)) {
      *(undefined4 *)(iVar8 + 0x3a8) = 0;
    }
    iVar8 = in_ECX[9];
    if ((iVar8 != 0) && (*(int *)(iVar8 + 0x3a8) != 0)) {
      *(undefined4 *)(iVar8 + 0x3a8) = 0;
    }
    uVar10 = DAT_00d6a62c;
    if (((DAT_00fba7b0 < 0x15) && (uVar10 = DAT_00d6a630, DAT_00fba7b0 < 0x10)) &&
       (uVar10 = DAT_00d6a634, DAT_00fba7b0 < 9)) {
      uVar10 = DAT_00d6a638;
    }
    uVar2 = *(int *)(DAT_00fb1318 + 0xbf74) * 2;
    if (uVar10 < uVar2) {
      uVar10 = uVar2;
    }
    if (((in_ECX[3] != 0) && (uVar10 < local_38)) && (0 < DAT_00fba7b0)) {
      if ((_DAT_00fe7268 & 1) == 0) {
        _DAT_00fe7268 = _DAT_00fe7268 | 1;
        DAT_00fe48d0 = 0;
        _atexit((_func_4879 *)&DAT_00bcf230);
      }
      uStack_28 = CONCAT22(uStack_28._2_2_,10);
      DAT_00fe48d0 = 6;
      _DAT_00fe38d0 = 10;
      _DAT_00fe38d2 = uStack_28._2_2_;
      _DAT_00fe38d4 = uStack_24;
      uStack_20 = (uint)uStack_20._2_2_ << 0x10;
      if ((DAT_00f94390 & 1) == 0) {
        DAT_00f94390 = DAT_00f94390 | 1;
        local_c = 0x10;
        FUN_004e1590();
        _atexit((_func_4879 *)&LAB_00bccc80);
        local_c = 0xffffffff;
      }
      _DAT_00fe38d2 = (undefined2)DAT_00f93944;
      _DAT_00fe38d4 = (undefined2)((uint)DAT_00f93944 >> 0x10);
      iVar8 = 0;
      do {
        piVar9 = (int *)in_ECX[iVar8 * 3 + 3];
        if ((piVar9 != (int *)0x0) && ((char)in_ECX[iVar8 * 3 + 5] != '\0')) {
          uVar1 = (undefined1)piVar9[0x2c];
          cVar3 = (**(code **)(*in_ECX + 0x48))(iVar8,&uStack_20);
          if (cVar3 == '\0') {
            if ((in_ECX[0x16] != 0) && ((*(ushort *)((int)in_ECX + 0x6a) & 0x8000) != 0)) {
              uStack_20 = uStack_20 & 0xffff;
              uStack_1c = uVar1;
              (**(code **)(*piVar9 + 0x58))(uVar1);
              if (iVar8 == 0) {
                in_ECX[0x1a] = uStack_20;
                *(undefined1 *)(in_ECX + 0x1b) = uStack_1c;
              }
              uStack_20 = CONCAT22(uStack_20._2_2_,(short)piVar9[1]);
              FUN_005471b0();
            }
          }
          else {
            if (in_ECX[0x16] != 0) {
              uStack_20 = uStack_20 & 0xffff;
              uStack_1c = uVar1;
              (**(code **)(*piVar9 + 0x58))(uVar1);
            }
            if (iVar8 == 0) {
              in_ECX[0x1a] = uStack_20;
              *(undefined1 *)(in_ECX + 0x1b) = uStack_1c;
            }
            uVar10 = DAT_00fe48d0;
            uStack_20 = CONCAT22(uStack_20._2_2_,(short)piVar9[1]);
            if (DAT_00fe48d0 + 5 < 0x1001) {
              *(uint *)(&DAT_00fe38d0 + DAT_00fe48d0) = uStack_20;
              (&DAT_00fe38d4)[uVar10] = uStack_1c;
              DAT_00fe48d0 = DAT_00fe48d0 + 5;
            }
          }
        }
        iVar8 = iVar8 + 1;
      } while (iVar8 < 3);
      uStack_3c = 0;
      if (in_ECX[0xd] - in_ECX[0xc] >> 3 != 0) {
        do {
          iVar8 = in_ECX[0xc];
          if ((DAT_00fab22c & 1) == 0) {
            DAT_00fab22c = DAT_00fab22c | 1;
            local_c = 0x11;
            FUN_004dec90();
            _atexit((_func_4879 *)&LAB_00bcce30);
            local_c = 0xffffffff;
          }
          uVar10 = (uint)*(ushort *)(iVar8 + uStack_3c * 8);
          cVar3 = *(char *)((int)DAT_00fab13c[1] + 0x15);
          puVar4 = (undefined4 *)DAT_00fab13c[1];
          puStack_34 = DAT_00fab13c;
          while (puVar7 = puVar4, cVar3 == '\0') {
            if ((uint)puVar7[3] < uVar10) {
              puVar4 = (undefined4 *)puVar7[2];
              puVar7 = puStack_34;
            }
            else {
              puVar4 = (undefined4 *)*puVar7;
            }
            cVar3 = *(char *)((int)puVar4 + 0x15);
            puStack_34 = puVar7;
          }
          if ((puStack_34 == DAT_00fab13c) || (uVar10 < (uint)puStack_34[3])) {
            puStack_30 = DAT_00fab13c;
            ppuVar5 = &puStack_30;
          }
          else {
            ppuVar5 = &puStack_34;
          }
          if ((*ppuVar5 != DAT_00fab13c) && (piVar9 = (int *)(*ppuVar5)[4], piVar9 != (int *)0x0)) {
            uStack_28 = piVar9[0x38];
            uStack_24 = CONCAT11(uStack_24._1_1_,(char)piVar9[0x39]);
            iVar8 = piVar9[0x2c];
            local_38 = CONCAT31(local_38._1_3_,(char)iVar8);
            iVar6 = (**(code **)(*in_ECX + 0x44))
                              (*(undefined2 *)(in_ECX[0xc] + uStack_3c * 8 + 2),piVar9,&uStack_28);
            if (iVar6 == 0) {
              if ((in_ECX[0x16] != 0) && ((*(ushort *)((int)in_ECX + 0x6a) & 0x8000) != 0))
              goto LAB_00545ac4;
            }
            else {
              if (in_ECX[0x16] != 0) {
LAB_00545ac4:
                uStack_28 = uStack_28 & 0xffff;
                uStack_24 = CONCAT11(uStack_24._1_1_,(char)iVar8);
                (**(code **)(*piVar9 + 0x58))(local_38);
              }
              if (uStack_3c == 0) {
                in_ECX[0x1a] = uStack_28;
                *(undefined1 *)(in_ECX + 0x1b) = (undefined1)uStack_24;
              }
              uVar10 = DAT_00fe48d0;
              uStack_28 = CONCAT22(uStack_28._2_2_,(short)piVar9[1]);
              if (DAT_00fe48d0 + 5 < 0x1001) {
                *(uint *)(&DAT_00fe38d0 + DAT_00fe48d0) = uStack_28;
                (&DAT_00fe38d4)[uVar10] = (undefined1)uStack_24;
                DAT_00fe48d0 = DAT_00fe48d0 + 5;
              }
            }
          }
          uStack_3c = uStack_3c + 1;
        } while (uStack_3c < (uint)(in_ECX[0xd] - in_ECX[0xc] >> 3));
      }
      piVar9 = DAT_00fba854;
      if (6 < DAT_00fe48d0) {
        DAT_00fba7b0 = DAT_00fba7b0 + -1;
        in_ECX[0x1d] = 0;
        in_ECX[0x19] = local_2c;
        (**(code **)(*piVar9 + 0x10))(0,&DAT_00fe38d0,DAT_00fe48d0);
      }
      *(undefined2 *)(in_ECX + 0x17) = 0;
    }
  }
LAB_00545b7d:
  if (in_ECX[0x16] != 0) {
    in_ECX[0x16] = 0;
  }
  ExceptionList = local_14;
  return 0;
}

