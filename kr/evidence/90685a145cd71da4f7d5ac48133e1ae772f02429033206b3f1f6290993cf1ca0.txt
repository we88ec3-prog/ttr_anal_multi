
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00561140(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  void **ppvVar4;
  uint uVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 *puVar8;
  bool bVar9;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093acae;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  puVar2 = *(undefined4 **)(param_1 + 0x1c);
  ppvVar4 = &local_10;
  puVar3 = (undefined4 *)*puVar2;
  local_10 = ExceptionList;
  do {
    do {
      while( true ) {
        do {
          puVar8 = puVar3;
          ExceptionList = ppvVar4;
          if (puVar8 == puVar2) {
            if ((_DAT_00fe38cc & 1) == 0) {
              _DAT_00fe38cc = _DAT_00fe38cc | 1;
              _DAT_00fe36e4 = 0x400;
              _DAT_00fe36e8 = 0x300;
              _DAT_00fe36ec = 0;
              _atexit((_func_4879 *)&DAT_00bcf2d0);
            }
            if (DAT_00fba7cc == 0) {
              iVar7 = FUN_00891268(0x1380);
              if (iVar7 == 0) {
                DAT_00fba7cc = 0;
              }
              else {
                *(undefined8 *)(iVar7 + 0x1350) = 0;
                *(undefined4 *)(iVar7 + 0x1370) = 1;
                *(undefined8 *)(iVar7 + 0x1358) = 0;
                *(undefined4 *)(iVar7 + 0x1374) = 1;
                *(undefined4 *)(iVar7 + 0x1378) = 0;
                *(undefined8 *)(iVar7 + 0x1368) = 0x3fa1111111111111;
                *(undefined4 *)(iVar7 + 0x1360) = 0x1e;
                FUN_006df660();
                DAT_00fba7cc = iVar7;
              }
            }
            iVar7 = DAT_00fba7cc;
            bVar9 = DAT_00d63d09 == '\0';
            if (!bVar9) {
              EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
              bVar9 = DAT_00d63d09 == '\0';
            }
            if (!bVar9) {
              LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
            }
            _DAT_00fe36e4 = *(undefined4 *)(iVar7 + 0x28);
            if (DAT_00fba7cc == 0) {
              iVar7 = FUN_00891268(0x1380);
              if (iVar7 == 0) {
                DAT_00fba7cc = 0;
              }
              else {
                *(undefined8 *)(iVar7 + 0x1350) = 0;
                *(undefined4 *)(iVar7 + 0x1370) = 1;
                *(undefined8 *)(iVar7 + 0x1358) = 0;
                *(undefined4 *)(iVar7 + 0x1374) = 1;
                *(undefined4 *)(iVar7 + 0x1378) = 0;
                *(undefined8 *)(iVar7 + 0x1368) = 0x3fa1111111111111;
                *(undefined4 *)(iVar7 + 0x1360) = 0x1e;
                FUN_006df660();
                DAT_00fba7cc = iVar7;
              }
            }
            iVar7 = DAT_00fba7cc;
            if ((DAT_00d63d09 != '\0') &&
               (EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8), DAT_00d63d09 != '\0')) {
              LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
            }
            _DAT_00fe36e8 = *(undefined4 *)(iVar7 + 0x2c);
            if ((DAT_00fe2740 & 1) == 0) {
              DAT_00fe2740 = DAT_00fe2740 | 1;
              local_8 = 0;
              FUN_0055e680();
              _atexit((_func_4879 *)&DAT_00bcf2a0);
              local_8 = 0xffffffff;
            }
            if (DAT_00fba7cc == 0) {
              iVar7 = FUN_00891268(0x1380);
              if (iVar7 == 0) {
                DAT_00fba7cc = 0;
              }
              else {
                *(undefined8 *)(iVar7 + 0x1350) = 0;
                *(undefined4 *)(iVar7 + 0x1370) = 1;
                *(undefined8 *)(iVar7 + 0x1358) = 0;
                *(undefined4 *)(iVar7 + 0x1374) = 1;
                *(undefined4 *)(iVar7 + 0x1378) = 0;
                *(undefined8 *)(iVar7 + 0x1368) = 0x3fa1111111111111;
                *(undefined4 *)(iVar7 + 0x1360) = 0x1e;
                FUN_006df660();
                DAT_00fba7cc = iVar7;
              }
            }
            iVar7 = DAT_00fba7cc;
            if ((DAT_00d63d09 != '\0') &&
               (EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8), DAT_00d63d09 != '\0')) {
              LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
            }
            _DAT_00fe2748 = *(undefined4 *)(iVar7 + 0x28);
            if (DAT_00fba7cc == 0) {
              iVar7 = FUN_00891268(0x1380);
              if (iVar7 == 0) {
                DAT_00fba7cc = 0;
              }
              else {
                *(undefined8 *)(iVar7 + 0x1350) = 0;
                *(undefined4 *)(iVar7 + 0x1370) = 1;
                *(undefined8 *)(iVar7 + 0x1358) = 0;
                *(undefined4 *)(iVar7 + 0x1374) = 1;
                *(undefined4 *)(iVar7 + 0x1378) = 0;
                *(undefined8 *)(iVar7 + 0x1368) = 0x3fa1111111111111;
                *(undefined4 *)(iVar7 + 0x1360) = 0x1e;
                FUN_006df660();
                DAT_00fba7cc = iVar7;
              }
            }
            iVar7 = DAT_00fba7cc;
            if ((DAT_00d63d09 == '\0') ||
               (EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8), DAT_00d63d09 == '\0')) {
              _DAT_00fe274c = *(undefined4 *)(iVar7 + 0x2c);
            }
            else {
              LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
              _DAT_00fe274c = *(undefined4 *)(iVar7 + 0x2c);
            }
            ExceptionList = local_10;
            return 0;
          }
          (**(code **)(*(int *)puVar8[4] + 0x18))(uVar5);
          ppvVar4 = ExceptionList;
          puVar3 = puVar8;
        } while (*(char *)((int)puVar8 + 0x15) != '\0');
        puVar3 = (undefined4 *)puVar8[2];
        if (*(char *)((int)puVar3 + 0x15) != '\0') break;
        cVar1 = *(char *)((int)*puVar3 + 0x15);
        puVar8 = (undefined4 *)*puVar3;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar8 + 0x15);
          puVar3 = puVar8;
          puVar8 = (undefined4 *)*puVar8;
        }
      }
      puVar3 = (undefined4 *)puVar8[1];
    } while (*(char *)((int)puVar3 + 0x15) != '\0');
    do {
      puVar6 = puVar3;
      puVar3 = puVar6;
      if (puVar8 != (undefined4 *)puVar6[2]) break;
      puVar3 = (undefined4 *)puVar6[1];
      puVar8 = puVar6;
    } while (*(char *)((int)puVar3 + 0x15) == '\0');
  } while( true );
}

