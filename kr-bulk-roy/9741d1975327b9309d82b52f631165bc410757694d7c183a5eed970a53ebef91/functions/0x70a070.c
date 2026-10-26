
void FUN_0070a070(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_006f6140("_LOADLIB");
  if ((HMODULE)*puVar1 != (HMODULE)0x0) {
    FreeLibrary((HMODULE)*puVar1);
  }
  *puVar1 = 0;
  return;
}

