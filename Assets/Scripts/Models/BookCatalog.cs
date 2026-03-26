using System.Collections.Generic;
using Newtonsoft.Json;

namespace ARBook.Models
{
    [System.Serializable]
    public class GeneralCatalog
    {
        public string version;
        public List<BookEntry> books;
    }

    [System.Serializable]
    public class BookEntry
    {
        public string id;
        public string title;
        public string description;

        [JsonProperty("addressable_group")]
        public string addressable_group;

        [JsonProperty("total_pages")]
        public int totalPages;

        [JsonProperty("json_file")]
        public string jsonFile;
    }
}