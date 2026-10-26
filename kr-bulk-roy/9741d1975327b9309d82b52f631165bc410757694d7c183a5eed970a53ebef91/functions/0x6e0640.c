
void FUN_006e0640(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  bool bVar4;
  
  if (DAT_00d63d09 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  bVar4 = DAT_00d63d09 != '\0';
  puVar2 = (undefined4 *)&stack0x00000008;
  puVar3 = (undefined4 *)(param_1 + 0x18c);
  for (iVar1 = 0x37; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  if (bVar4) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  return;
}

