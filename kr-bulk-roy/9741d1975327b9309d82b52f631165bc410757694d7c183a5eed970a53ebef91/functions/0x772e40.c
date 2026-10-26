
void FUN_00772e40(undefined4 *param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = ExceptionList;
  puStack_c = &LAB_0090a643;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = FoxUI::FXUIFontType::vftable;
  local_8 = 5;
  puVar2 = (undefined4 *)param_1[0x18];
  puVar3 = (undefined4 *)*puVar2;
  while (puVar3 != puVar2) {
    if ((int *)puVar3[4] != (int *)0x0) {
      (**(code **)(*(int *)puVar3[4] + 0x1c))(1,uVar4);
      puVar3[4] = 0;
    }
    if (*(char *)((int)puVar3 + 0x15) == '\0') {
      puVar6 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar6 + 0x15) == '\0') {
        cVar1 = *(char *)((int)*puVar6 + 0x15);
        puVar3 = puVar6;
        puVar6 = (undefined4 *)*puVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar6 + 0x15);
          puVar3 = puVar6;
          puVar6 = (undefined4 *)*puVar6;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x15);
        puVar5 = (undefined4 *)puVar3[1];
        puVar6 = puVar3;
        while ((puVar3 = puVar5, cVar1 == '\0' && (puVar6 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x15);
          puVar5 = (undefined4 *)puVar3[1];
          puVar6 = puVar3;
        }
      }
    }
  }
  FUN_00823850();
  puVar2 = (undefined4 *)param_1[0x1c];
  puVar3 = (undefined4 *)*puVar2;
  do {
    do {
      while( true ) {
        do {
          puVar6 = puVar3;
          if (puVar6 == puVar2) {
            FUN_00823850();
            local_8._0_1_ = 6;
            FUN_005540c0(*(undefined4 *)param_1[0x1c],(undefined4 *)param_1[0x1c]);
            FUN_0089120c(param_1[0x1c]);
            local_8 = CONCAT31(local_8._1_3_,7);
            FUN_005540c0(*(undefined4 *)param_1[0x18],(undefined4 *)param_1[0x18]);
            FUN_0089120c(param_1[0x18]);
            if (7 < (uint)param_1[0x15]) {
              FUN_0089120c(param_1[0x10]);
            }
            param_1[0x15] = 7;
            param_1[0x14] = 0;
            *(undefined2 *)(param_1 + 0x10) = 0;
            if (7 < (uint)param_1[0xe]) {
              FUN_0089120c(param_1[9]);
            }
            param_1[0xe] = 7;
            param_1[0xd] = 0;
            *(undefined2 *)(param_1 + 9) = 0;
            if (7 < (uint)param_1[7]) {
              FUN_0089120c(param_1[2]);
            }
            param_1[7] = 7;
            param_1[6] = 0;
            *(undefined2 *)(param_1 + 2) = 0;
            *param_1 = FoxUI::FXUIArchive::vftable;
            ExceptionList = local_10;
            return;
          }
          if ((int *)puVar6[4] != (int *)0x0) {
            (**(code **)(*(int *)puVar6[4] + 0x1c))(1);
            puVar6[4] = 0;
          }
          puVar3 = puVar6;
        } while (*(char *)((int)puVar6 + 0x15) != '\0');
        puVar3 = (undefined4 *)puVar6[2];
        if (*(char *)((int)puVar3 + 0x15) != '\0') break;
        cVar1 = *(char *)((int)*puVar3 + 0x15);
        puVar6 = (undefined4 *)*puVar3;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar6 + 0x15);
          puVar3 = puVar6;
          puVar6 = (undefined4 *)*puVar6;
        }
      }
      puVar3 = (undefined4 *)puVar6[1];
    } while (*(char *)((int)puVar3 + 0x15) != '\0');
    do {
      puVar5 = puVar3;
      puVar3 = puVar5;
      if (puVar6 != (undefined4 *)puVar5[2]) break;
      puVar3 = (undefined4 *)puVar5[1];
      puVar6 = puVar5;
    } while (*(char *)((int)puVar3 + 0x15) == '\0');
  } while( true );
}

