
undefined4 FUN_005cf550(undefined4 param_1,int param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  int *piVar6;
  ushort uVar7;
  int *piVar8;
  int iStack_84;
  int *piStack_80;
  int iStack_7c;
  undefined1 *puStack_78;
  undefined1 *puStack_74;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined1 auStack_5c [4];
  undefined4 *puStack_58;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined1 auStack_40 [12];
  undefined1 auStack_34 [4];
  undefined4 *puStack_30;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093f3fe;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90(DAT_00d61f20 ^ (uint)&stack0xffffff70);
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  local_c = 0xffffffff;
  if (DAT_00fba7a4 != (int *)0x0) {
    iVar2 = (**(code **)(*DAT_00fba7a4 + 0x20))();
    if (iVar2 != 0) {
      uVar7 = *(ushort *)(iVar2 + 0x88);
      iVar2 = FUN_00404ba0();
      if (((uVar7 < 10) &&
          (iVar2 = *(int *)(iVar2 + 0x6924) + (uint)uVar7 * 0x210, *(int *)(iVar2 + 0x5c) != 0)) &&
         (iVar2 != 0)) {
        iStack_84 = param_2;
        iVar2 = FUN_0046ff20();
        FUN_00835c70(&iStack_84);
        if ((piStack_80 != (int *)*(int *)(iVar2 + 4)) &&
           (iStack_7c = (int)piStack_80 + 0x10, iStack_7c != 0)) {
          FUN_00404ba0();
          FUN_004d4520();
          piVar8 = (int *)**(int **)((int)piStack_80 + 0x14);
          if (piVar8 != *(int **)((int)piStack_80 + 0x14)) {
            iStack_84 = (int)piVar8;
            piStack_80 = (int *)FUN_004d4210();
            puStack_78 = auStack_5c;
            do {
              iVar2 = *(int *)((int)piVar8 + 0xc);
              piVar8 = (int *)*piStack_80;
              uVar3 = piStack_80[1] - (int)piVar8 >> 3;
              uVar5 = 0;
              piVar6 = piVar8;
              if (uVar3 != 0) {
                do {
                  if (*piVar6 == iVar2) {
                    uVar7 = *(ushort *)(piVar8 + uVar5 * 2 + 1);
                    goto LAB_005cf6c2;
                  }
                  uVar5 = uVar5 + 1;
                  piVar6 = piVar6 + 2;
                } while (uVar5 < uVar3);
              }
              uVar7 = 0;
LAB_005cf6c2:
              FUN_00830e10();
              local_c = 1;
              uStack_68 = 0;
              uStack_48 = 0;
              uStack_60 = 0;
              uStack_64 = 0;
              uStack_44 = 0;
              cVar1 = FUN_005cf860(&uStack_68,param_2,iVar2,uVar7 & 0xff);
              if (cVar1 != '\0') {
                uVar4 = FUN_00830d00(auStack_40,param_1,&uStack_68);
                local_c._0_1_ = 2;
                FUN_005cf7e0(uVar4);
                puStack_74 = auStack_34;
                local_c = CONCAT31(local_c._1_3_,3);
                FUN_004ca160(*puStack_30,puStack_30);
                FUN_0089120c(puStack_30);
              }
              local_c = 4;
              FUN_004ca160(*puStack_58,puStack_58);
              local_c = 0xffffffff;
              FUN_0089120c(puStack_58);
              FUN_0079c460();
              piVar8 = (int *)iStack_84;
            } while (iStack_84 != *(int *)(iStack_7c + 4));
          }
          ExceptionList = local_14;
          return 1;
        }
      }
    }
  }
  ExceptionList = local_14;
  return 0;
}

