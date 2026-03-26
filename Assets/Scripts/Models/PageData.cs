using System.Collections.Generic;

namespace ARBook.Models
{
    [System.Serializable]
    public class PageData
    {
        public string id;
        public string nom;
        public string feuille;
        public List<ItemData> items;
    }
}