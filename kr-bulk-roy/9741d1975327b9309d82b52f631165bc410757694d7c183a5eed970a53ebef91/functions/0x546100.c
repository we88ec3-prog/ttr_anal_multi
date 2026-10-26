
uint FUN_00546100(int param_1,int param_2)

{
  uint uVar1;
  void **ppvVar2;
  int iVar3;
  undefined4 uVar4;
  undefined2 extraout_var;
  undefined2 uVar5;
  int in_ECX;
  int iVar6;
  int *piVar7;
  bool bVar8;
  float10 fVar9;
  undefined1 local_35;
  undefined4 local_30;
  undefined4 local_2c;
  void **local_28;
  float local_24;
  undefined4 local_20;
  char local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093fe6c;
  local_14 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffffb8;
  ExceptionList = &local_14;
  piVar7 = *(int **)(in_ECX + 0xc);
  local_35 = 0;
  ppvVar2 = ExceptionList;
  if (DAT_00fba7ac == 3) {
    ppvVar2 = (void **)(param_1 * 3 + 3);
    piVar7 = *(int **)(in_ECX + (int)ppvVar2 * 4);
  }
  iVar6 = 0;
  if (piVar7 == (int *)0x0) {
    *(undefined4 *)(in_ECX + 0x7c) = 0;
    *(undefined4 *)(in_ECX + 0x80) = 0;
LAB_0054615a:
    ExceptionList = local_14;
    return (uint)ppvVar2 & 0xffffff00;
  }
  local_1c = (char)piVar7[0x39];
  local_20 = piVar7[0x38];
  iVar3 = piVar7[0x2c];
  *(undefined2 *)(param_2 + 2) = 0;
  *(char *)(param_2 + 4) = (char)piVar7[0x2c];
  local_30 = CONCAT31(local_30._1_3_,(char)iVar3);
  local_2c = 0;
  if ((piVar7[0x56] == 0) || (*(int *)(piVar7[0x56] + 0x34) != 0)) {
    *(undefined4 *)(in_ECX + 0x7c) = 0;
    *(undefined4 *)(in_ECX + 0x80) = 0;
  }
  local_24 = 0.0;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(uVar1);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  ppvVar2 = (void **)(uint)*(ushort *)(piVar7 + 0x22);
  if ((((void **)0x9 < ppvVar2) ||
      (ppvVar2 = (void **)((int)ppvVar2 * 0x210 + DAT_00f94304), ppvVar2[0x17] == (void *)0x0)) ||
     (ppvVar2 == (void **)0x0)) goto LAB_0054615a;
  local_28 = ppvVar2 + 0x7d;
  ppvVar2 = (void **)0x0;
  if (local_28 == (void **)0x0) goto LAB_0054615a;
  if (piVar7[0x56] != 0) {
    iVar6 = *(int *)(piVar7[0x56] + 0x2c);
  }
  iVar3 = FUN_004c9ed0();
  if ((iVar6 != 0) && (iVar3 == 0)) {
    local_24 = (float)FUN_00546780(piVar7,&local_30,&local_2c);
    iVar6 = FUN_00444960();
    if (*(char *)(iVar6 + 0x7ef) == '\x01') {
      local_35 = 1;
      uVar4 = 0x100;
LAB_0054628f:
      *(ushort *)(param_2 + 2) =
           *(ushort *)(param_2 + 2) ^ (*(ushort *)(param_2 + 2) ^ (ushort)uVar4) & 0x7fff;
    }
    else {
      uVar4 = local_2c;
      if ((short)local_2c != 0) goto LAB_0054628f;
    }
    if ((DAT_00fba7ac != 1) && ((short)uVar4 != 0)) {
      local_28 = (void **)CONCAT31(local_28._1_3_,
                                   *(undefined1 *)
                                    ((uint)(*(char *)((int)local_28 + 2) != '\0') + (int)local_28));
      iVar6 = FUN_0054f270(local_28,piVar7[0xfa]);
      if (iVar6 == 0) {
        if (piVar7[0xfa] == 0) {
          *(ushort *)(param_2 + 2) = *(ushort *)(param_2 + 2) & 0x8000;
        }
        else {
          local_35 = 1;
        }
      }
      else {
        local_35 = 1;
      }
    }
  }
  if ((DAT_00fb7c14 & 1) == 0) {
    DAT_00fb7c14 = DAT_00fb7c14 | 1;
    local_c = 1;
    FUN_006d0750();
    _atexit((_func_4879 *)&LAB_00bcd530);
    local_c = 0xffffffff;
  }
  bVar8 = DAT_00fb9009 == '\0';
  iVar6 = piVar7[0x56];
  if ((iVar6 != 0) && (*(int *)(iVar6 + 0x30) != 0)) {
    iVar6 = FUN_004c9ed0();
    if ((iVar6 == 0) && (bVar8)) {
      *(undefined1 *)(param_2 + 4) = (undefined1)local_30;
      uVar5 = 0;
      if ((local_24 != 0.0) && ((*(ushort *)(param_2 + 2) & 0x7fff) == 0)) {
        fVar9 = (float10)(**(code **)(*piVar7 + 0x60))();
        local_24 = (float)(fVar9 * (float10)0.03333330154418945);
        iVar6 = FUN_00545f30(*(undefined1 *)(param_2 + 4),local_24);
        *(undefined4 *)(in_ECX + 0x70) = 0;
        if ((iVar6 == 0) && (*(int *)(in_ECX + 0x74) == 0)) {
          if (piVar7[0xea] != 0) {
            piVar7[0xea] = 0;
          }
          if (((piVar7[0x56] == 0) || (*(int *)(piVar7[0x56] + 0x28) == 0)) ||
             ((*(ushort *)(param_2 + 2) & 0x7fff) != 0)) {
            *(ushort *)(param_2 + 2) = *(ushort *)(param_2 + 2) & 0x7fff;
          }
          else {
            *(ushort *)(param_2 + 2) = *(ushort *)(param_2 + 2) | 0x8000;
          }
        }
        else {
          iVar6 = param_2 + 4;
          uVar4 = local_30;
          fVar9 = (float10)(**(code **)(*piVar7 + 0x60))(local_30,iVar6);
          uVar4 = FUN_005464c0(*(undefined4 *)(in_ECX + 0x74),(float)fVar9,uVar4,iVar6);
          *(undefined4 *)(in_ECX + 0x70) = uVar4;
          *(ushort *)(param_2 + 2) = *(ushort *)(param_2 + 2) | 0x8000;
          if (*(int *)(in_ECX + 0x70) != 0) {
            FUN_004c90c0(1);
          }
        }
        (**(code **)(*piVar7 + 0x58))(*(undefined1 *)(param_2 + 4));
        uVar5 = extraout_var;
        if (*(char *)(param_2 + 4) != local_1c) {
          local_35 = 1;
        }
      }
      *(undefined4 *)(in_ECX + 0x74) = 0;
      goto LAB_00546485;
    }
  }
  uVar5 = (undefined2)((uint)iVar6 >> 0x10);
  *(ushort *)(param_2 + 2) = *(ushort *)(param_2 + 2) & 0x7fff;
LAB_00546485:
  local_20._2_2_ = *(ushort *)(param_2 + 2) ^ local_20._2_2_;
  if ((local_20._2_2_ & 0x8000) != 0) {
    local_35 = 1;
  }
  ExceptionList = local_14;
  return CONCAT31((int3)(CONCAT22(uVar5,local_20._2_2_) >> 8),local_35);
}

