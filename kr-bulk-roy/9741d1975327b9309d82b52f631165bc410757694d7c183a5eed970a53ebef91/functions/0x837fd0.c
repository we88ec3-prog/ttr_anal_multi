
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00837fd0(void)

{
  uint *puVar1;
  uint uVar2;
  longlong lVar3;
  undefined *puVar4;
  HANDLE pvVar5;
  int iVar6;
  uint uVar7;
  WORD WVar8;
  uint local_48;
  int iStack_44;
  
  puVar4 = PTR_PTR_00d639fc;
  FUN_008381b0();
  uVar7 = local_48 - *(uint *)(puVar4 + 0x10);
  iVar6 = (iStack_44 - *(int *)(puVar4 + 0x14)) - (uint)(local_48 < *(uint *)(puVar4 + 0x10));
  puVar1 = (uint *)(puVar4 + 0x18);
  uVar2 = *puVar1;
  *puVar1 = *puVar1 + uVar7;
  *(uint *)(puVar4 + 0x28) = uVar7;
  *(int *)(puVar4 + 0x2c) = iVar6;
  *(uint *)(puVar4 + 0x1c) = *(int *)(puVar4 + 0x1c) + iVar6 + (uint)CARRY4(uVar2,uVar7);
  if ((*(int *)(puVar4 + 0x24) <= iVar6) &&
     ((*(int *)(puVar4 + 0x24) < iVar6 || (*(uint *)(puVar4 + 0x20) < uVar7)))) {
    *(uint *)(puVar4 + 0x20) = uVar7;
    *(int *)(puVar4 + 0x24) = iVar6;
  }
  if (((DAT_00fba921 != '\0') && (DAT_00fba92c <= iVar6)) &&
     ((DAT_00fba92c < iVar6 || (DAT_00fba928 < uVar7)))) {
    WVar8 = 10;
    pvVar5 = GetStdHandle(0xfffffff5);
    SetConsoleTextAttribute(pvVar5,WVar8);
    if (DAT_00fe3478 == 0 && _DAT_00fe347c == 0) {
      FUN_00838150();
    }
    lVar3 = __allmul(uVar7,iVar6,1000,0);
    FID_conflict__wprintf
              ("Profile Warning : name-%s, time-%.3fms\n",*(undefined4 *)puVar4,
               (double)lVar3 / (double)CONCAT44(_DAT_00fe347c,DAT_00fe3478));
    WVar8 = 7;
    pvVar5 = GetStdHandle(0xfffffff5);
    SetConsoleTextAttribute(pvVar5,WVar8);
  }
  return;
}

