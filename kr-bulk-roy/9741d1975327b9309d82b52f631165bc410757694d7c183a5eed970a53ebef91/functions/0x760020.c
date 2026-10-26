
void FUN_00760020(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *in_ECX;
  undefined4 *puVar6;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = ExceptionList;
  puStack_c = &LAB_0091583e;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = FoxUI::
            FXUITabContainerNavigator<FoxUI::FXUITabContainer<FoxUI::FXUITabBoxNavigator,FoxUI::FXUITabBoxContent,FoxUI::FXUIWindow>,FoxUI::FXUIWindow,FoxUI::FXUIContentButton>
            ::vftable;
  local_8 = 2;
  puVar2 = (undefined4 *)in_ECX[0x2b];
  puVar3 = (undefined4 *)*puVar2;
  do {
    do {
      while( true ) {
        do {
          puVar6 = puVar3;
          if (puVar6 == puVar2) {
            FUN_00823850();
            puVar2 = (undefined4 *)in_ECX[0x2f];
            puVar3 = (undefined4 *)*puVar2;
            while (puVar3 != puVar2) {
              if ((int *)puVar3[4] != (int *)0x0) {
                (**(code **)(*(int *)puVar3[4] + 0x1c))(1);
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
            local_8._0_1_ = 3;
            FUN_005540c0(*(undefined4 *)in_ECX[0x2f],(undefined4 *)in_ECX[0x2f]);
            FUN_0089120c(in_ECX[0x2f]);
            local_8 = CONCAT31(local_8._1_3_,4);
            FUN_005540c0(*(undefined4 *)in_ECX[0x2b],(undefined4 *)in_ECX[0x2b]);
            FUN_0089120c(in_ECX[0x2b]);
            *in_ECX = FoxUI::FXUIControl::vftable;
            local_8 = 5;
            FUN_00744370();
            local_8 = 0xffffffff;
            *in_ECX = FoxUI::FXUIRDTarget::vftable;
            FUN_00745380();
            ExceptionList = local_10;
            return;
          }
          if ((int *)puVar6[4] != (int *)0x0) {
            (**(code **)(*(int *)puVar6[4] + 0x1c))(1,uVar4);
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

